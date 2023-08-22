/*
 * Copyright (c) 2023--present, WILLIAM WEI.  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <iostream>
#include <iomanip>
#include <Eigen/Core>
#include <Eigen/Geometry>

// #include <pangolin/pangolin.h>

namespace slamdunk {
    struct RotationMatrix {
        Eigen::Matrix3d matrix = Eigen::Matrix3d::Identity();

        void print() const {
            std::cout
              << "[" << std::setprecision(std::ios::fixed) << matrix(0, 0) << "," << matrix(0, 1)
              << "," << matrix(0, 2) << "]"
              << "\n"
              << "[" << matrix(1, 0) << "," << matrix(1, 1) << "," << matrix(1, 2) << "]"
              << "\n"
              << "[" << matrix(2, 0) << "," << matrix(2, 1) << "," << matrix(2, 2) << "]"
              << std::endl;
        }
    };

    struct TranslationVector {
        Eigen::Vector3d trans = Eigen::Vector3d(0.f, 0.f, 0.f);

        void print() const {
            std::cout << "[" << trans(0) << ',' << trans(1) << ',' << trans(2) << "]" << std::endl;
        }
    };

    struct QuaternionVector {
        Eigen::Quaterniond q = Eigen::Quaterniond(0.0f, 0.0f, 0.0f, 0.0f);

        void print() const {
            std::cout << "[" << q.coeffs()[0] << ',' << q.coeffs()[1] << ',' << q.coeffs()[2] << ","
                      << q.coeffs()[3] << "]" << std::endl;
        }
    };

} // namespace slamdunk