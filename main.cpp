/* switchfl1p 2025-2026 */

#include <glm/glm.hpp>
#include <Timer.hpp>
#include <Interpolators.hpp>
#include <InterpolatorTraits.hpp>

int main() {
    /*
    Initalization example of a constant velocity linear interpolator for positions, aka glm:vec3 
    With a 10 sec duration looping timer
    Needs distance() defined in InterpolatorTraits.hpp
    */
    ConstVelLinearInterpolator<glm::vec3> position_interpolator;
    Timer position_timer(Timer::TT_LOOP, 10.0f);

    std::vector<glm::vec3> position_values;
    position_values.push_back(glm::vec3(-5.0f, 1.5f, 8.0f));
	position_values.push_back(glm::vec3(-2.0f, 3.0f, 5.0f));   
    position_interpolator.setValues(position_values);

    /*
    Initalization example of a timed linear interpolator for colours, aka a glm::vec4
    With a 15 sec duration single timer
    Needs getValue() and getTime defined in InterpolatorTraits.hpp
    Timed linear interpolators require both a value and a time
    */
    TimedLinearInterpolator<glm::vec4> color_interpolator;
    Timer color_timer(Timer::TT_SINGLE, 15.0f);

    std::vector<std::pair<glm::vec4, float>> color_time_pairs;
    color_time_pairs.push_back(std::pair<glm::vec4, float>(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), 0.0f));
    color_time_pairs.push_back(std::pair<glm::vec4, float>(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 1.0f));
    color_interpolator.setValues(color_time_pairs);

    /*
    Initalization example of a timed linear interpolator for maximum intensities, aka a float
    With a 20 sec duration looping timer
    Needs getValue() and getTime defined in InterpolatorTraits.hpp
    Timed linear interpolators require both a value and a time
    */
    TimedLinearInterpolator<float> max_intensity_interpolator;
    Timer max_intens_timer(Timer::TT_LOOP, 20.0f);

    std::vector<std::pair<float, float>> max_intens_pairs;
    max_intens_pairs.push_back(std::pair<float, float>(0.0f, 0.0f));
    max_intens_pairs.push_back(std::pair<float, float>(1.0f, 1.0f));
    max_intensity_interpolator.setValues(max_intens_pairs);

    /*
    Initalization example of a linear interpolator for colors, aka a float
    With a 25 sec duration looping timer
    */
    LinearInterpolator<glm::vec4> linear_colors_interpolator;
    Timer linear_colors_timer(Timer::TT_LOOP, 25.0f);

    std::vector<glm::vec4> linear_color_values;
    linear_color_values.push_back(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    linear_color_values.push_back(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    linear_colors_interpolator.setValues(linear_color_values);

    /*
    During your display loop, called every frame
    Update the timers and get the interpolated value
    */
    position_timer.update();
    glm::vec4 interpolated_position = glm::vec4(position_interpolator.interpolate(position_timer.getAlpha()), 1.0f);

    color_timer.update();
    glm::vec4 interpolated_color = color_interpolator.interpolate(color_timer.getAlpha());

    max_intens_timer.update();
    float interpolated_max_intensitiy = max_intensity_interpolator.interpolate(max_intens_timer.getAlpha());

    linear_colors_timer.update();
    glm::vec4 interpolated_linear_color = linear_colors_interpolator.interpolate(linear_colors_timer.getAlpha());

}