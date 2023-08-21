FILE(GLOB inrto_sources ${CMAKE_CURRENT_LIST_DIR}/*.cc)
message(STATUS "library sources are: " ${inrto_sources})
add_library(intro SHARED ${inrto_sources})

target_include_directories(
        intro
        PUBLIC
        ${OpenCV_INCLUDE_DIRS}
        ${EIGEN3_INCLUDE_DIR}
)