cmake_minimum_required(VERSION 3.25)
project(slamdunk LANGUAGES C CXX)


find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(intro)

add_executable(slamdunk main.cc)

target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${EIGEN3_INCLUDE_DIR}
        ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(
        ${PROJECT_NAME}
        ${OpenCV_LIBS}
        libintro
)
