# ----- GLM (header only) ------
add_library(glm INTERFACE)
target_include_directories(glm INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/glm)

# ----- GLFW -----
set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/GLFW)
