cmake_minimum_required(VERSION 3.20)
project(slamdunk LANGUAGES C CXX)


find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)
# find_package(Pangolin REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_subdirectory(intro)
add_subdirectory(math)
add_subdirectory(visualize)
add_executable(slamdunk main.cc)

target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${EIGEN3_INCLUDE_DIR}
        ${OpenCV_INCLUDE_DIRS}
        # ${Pangolin_INCLUDE_DIRS}
)

target_link_libraries(
        ${PROJECT_NAME}
        ${OpenCV_LIBS}
        # ${Pangolin_LIBRARIES}
        intro
        slammath
        slamvis
)
