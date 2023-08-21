#include "intro/hello_slam.h"
#include "intro/intro_eigen.h"
#include "intro/coordinate_transform.h"
#include "math/rodrigues.h"
#include <iostream>

int main() {
    Eigen::Vector3f v(1.0f, 0.0f, 0.0f);
    Eigen::Vector3f k(0.0f, 0.0f, 1.0f);
    float theta = M_PI / 2; // 90 degrees

    Eigen::Vector3f v_prime = slamdunk::rodrigues_rotation<float>(v, k, theta);
    std::cout << v_prime.transpose() << std::endl;

    auto v_prime_1 = slamdunk::rodriguesRotation(v, k, theta);
    std::cout << v_prime_1.transpose() << std::endl;

    float theta_r = slamdunk::rotation2degrees(v_prime);
    std::cout << theta_r << std::endl;
    std::cout << theta << std::endl;
    return 0;
}
