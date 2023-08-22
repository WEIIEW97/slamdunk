FILE(GLOB vis_sources ${CMAKE_CURRENT_LIST_DIR}/*.cc)
FILE(GLOB vis_headers ${CMAKE_CURRENT_LIST_DIR}/*.h)

# message(STATUS "library sources are: " ${vis_sources} ${vis_headers})
add_library(slamvis SHARED ${vis_sources} ${vis_headers})

target_include_directories(
        slamvis
        PUBLIC
        ${EIGEN3_INCLUDE_DIR}
        # ${Pangolin_INCLUDE_DIRS}
)