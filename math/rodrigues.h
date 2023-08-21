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

#include <cmath>
#include <Eigen/Core>

namespace slamdunk {
    template <typename T>
    Eigen::Vector<T, 3> rodrigues_rotation(Eigen::Vector<T, 3> v, Eigen::Vector<T, 3> n, T theta) {
        auto unit_n = n.normalized();
        auto I_3x3 = Eigen::Matrix<T, 3, 3>::Identity();
        return (I_3x3 * std::cos(theta) + (1 - std::cos(theta)) * unit_n * unit_n.transpose()) * v
             + (unit_n.cross(v) * std::sin(theta));
    }

    Eigen::Vector3f
      rodriguesRotation(const Eigen::Vector3f& v, const Eigen::Vector3f& k, float theta);
    
    // got mistake!
    template <typename T>
    T rotation2degrees(Eigen::Vector<T, 3> v) {
        return std::acos((v.trace() - 1) / 2);
    }

} // namespace slamdunk