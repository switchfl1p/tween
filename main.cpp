/* switchfl1p 2025-2026 */

#include <iostream>
#include <Timer.hpp>
#include <Interpolators.hpp>

#include <glm/glm.hpp>

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
    std::cout << "Hello World!\n";
}