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

#include "coordinate_transform.h"

namespace slamdunk {
    void coordinate_transform() {
        Eigen::Quaterniond q1(0.35, 0.2, 0.3, 0.1), q2(-0.5, 0.4, -0.1, 0.2);
        std::cout << "initial quaternion q1: " << q1 << std::endl;
        std::cout << "initial quaternion q2: " << q2 << std::endl;
        q1.normalize();
        q2.normalize();

        std::cout << "normalized quaternion q1: " << q1 << std::endl;
        std::cout << "normalized quaternion q2: " << q2 << std::endl;

        Eigen::Vector3d t1(0.3, 0.1, 0.1), t2(-0.1, 0.5, 0.3);
        Eigen::Vector3d p1(0.5, 0, 0.2);

        Eigen::Isometry3d T1w(q1), T2w(q2);
        T1w.pretranslate(t1);
        T2w.pretranslate(t2);

        Eigen::Vector3d p2 = T2w * T1w.inverse() * p1;
        std::cout << "p2 is: \n" << p2.transpose() << std::endl;
    }
} // namespace slamdunk
