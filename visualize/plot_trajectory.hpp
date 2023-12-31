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

#include <pangolin/pangolin.h>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <unistd.h>

namespace slamdunk {
    class TrajectoryPlot {
       public:
        std::string input_path_;
        TrajectoryPlot(std::string input_path);
        ~TrajectoryPlot() = default;

        private:
        void create_window(std::vector<Eigen::Isometry3d, Eigen::aligned_allocator<Eigen::Isometry3d>> poses);

        public:
        void draw();
    };
} // namespace slamdunk
