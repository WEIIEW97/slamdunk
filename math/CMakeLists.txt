FILE(GLOB math_sources ${CMAKE_CURRENT_LIST_DIR}/*.cc)
FILE(GLOB math_headers ${CMAKE_CURRENT_LIST_DIR}/*.h)

# message(STATUS "library sources are: " ${math_sources} ${math_headers})
add_library(slammath SHARED ${math_sources})

target_include_directories(
        slammath
        PUBLIC
        ${EIGEN3_INCLUDE_DIR}
)