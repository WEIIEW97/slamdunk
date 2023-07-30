add_library(libintro SHARED hello_slam.cc intro_eigen.cc)

target_include_directories(
        libintro
        PUBLIC
        ${OpenCV_INCLUDE_DIRS}
        ${EIGEN3_INCLUDE_DIR}
)