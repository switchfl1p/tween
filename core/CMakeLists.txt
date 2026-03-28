set(CORE_SOURCES
    Timer.cpp
)

set(CORE_HEADERS
    Timer.hpp
    Interpolators.hpp
)

add_library(core STATIC ${CORE_SOURCES} ${CORE_HEADERS})
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(core PUBLIC glm glfw)
