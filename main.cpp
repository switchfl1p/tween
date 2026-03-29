/* switchfl1p 2025-2026 */

#include <glm/glm.hpp>
#include <Timer.hpp>
#include <Interpolators.hpp>

float distance(const glm::vec3 &lhs, const glm::vec3 &rhs) {
    return glm::length(rhs - lhs);
}

glm::vec4 getValue(const std::pair<glm::vec4, float> &light_vector_data) {
    return light_vector_data.first;
}

float getTime(const std::pair<glm::vec4, float> &light_vector_data) {
    return light_vector_data.second;
}

float getValue(const std::pair<float, float> &max_intensity_data) {
    return max_intensity_data.first;
}

float getTime(const std::pair<float, float> &max_intensity_data) {
    return max_intensity_data.second;
}

int main() {
    ConstVelLinearInterpolator<glm::vec3> position_interpolator;
    Timer position_timer(Timer::TT_LOOP, 10.0f);
    std::vector<glm::vec3> position_values;

    position_values.push_back(glm::vec3(-5.0f, 1.5f, 8.0f));
	position_values.push_back(glm::vec3(-2.0f, 3.0f, 5.0f));   
    position_interpolator.setValues(position_values);

    TimedLinearInterpolator<glm::vec4> color_interpolator;
    Timer color_timer(Timer::TT_SINGLE, 15.0f);
    std::vector<std::pair<glm::vec4, float>> color_time_pairs;

    color_time_pairs.push_back(std::pair<glm::vec4, float>(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), 1.0f));
    color_time_pairs.push_back(std::pair<glm::vec4, float>(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 1.0f));

    color_interpolator.setValues(color_time_pairs);

    //during your display loop
    position_timer.update();
    glm::vec4 interpolated_position = glm::vec4(position_interpolator.interpolate(position_timer.getAlpha()), 1.0f);

    color_timer.update();
    glm::vec4 interpolated_color = color_interpolator.interpolate(color_timer.getAlpha());
}