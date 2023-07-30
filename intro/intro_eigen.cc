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
#include "intro_eigen.h"
#include <ctime>
#include <iostream>

using namespace Eigen;
using std::cout, std::endl;

#define MATRIX_SIZE 50

namespace slamdunk {
void show_basic_eigen_op()
{
    Matrix<float, 2, 3> matrix_23;
    Vector3d            v_3d;
    Matrix<float, 3, 1> vd_3d;

    Matrix3d                         matrix_33 = Matrix3d::Zero();
    Matrix<double, Dynamic, Dynamic> matrix_dynamic;
    MatrixXd                         matrix_x;
    matrix_23 << 1, 2, 3, 4, 5, 6;
    cout << "matrix 2x3 from 1 to 6 :\n" << matrix_23 << endl;

    cout << "print matrix 2x3: \n" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix_23(i, j) << "\t";
            cout << endl;
        }
    }

    v_3d << 3, 2, 1;
    vd_3d << 4, 5, 6;

    Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
    cout << "[1,2,3;4,5,6]∗[3,2,1]=" << result.transpose() << endl;

    Matrix<float, 2, 1> result2 = matrix_23 * vd_3d;
    cout << "[1,2,3;4,5,6]∗[4,5,6]: " << result2.transpose() << endl;

    auto m33 = Matrix3d::Random();
    cout << "random matrix: \n" << m33 << endl;
    cout << "transpose: \n" << m33.transpose() << endl;
    cout << "sum: \n" << m33.sum() << endl;
    cout << "trace: \n" << m33.trace() << endl;
    cout << "times 10: \n" << m33 * 10 << endl;
    cout << "inverse: \n" << m33.inverse() << endl;
    cout << "det: \n" << m33.determinant() << endl;

    // eigen values
    SelfAdjointEigenSolver<Matrix3d> eigen_solver(m33.transpose() * m33);
    cout << "eigen values = \n" << eigen_solver.eigenvalues() << endl;
    cout << "eigen vectors = \n" << eigen_solver.eigenvectors() << endl;

    // solving equations
    Matrix<double, MATRIX_SIZE, MATRIX_SIZE> mNN = MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
    mNN                                          = mNN * mNN.transpose();
    Matrix<double, MATRIX_SIZE, 1> v_Nd          = MatrixXd::Random(MATRIX_SIZE, 1);

    clock_t                        time_stt = clock();
    Matrix<double, MATRIX_SIZE, 1> x        = mNN.inverse() * v_Nd;
    cout << "time of normal inverse is " << 1000 * (clock() - time_stt) / static_cast<double>(CLOCKS_PER_SEC) << "ms"
         << endl;
    cout << "x = " << x.transpose() << endl;

    time_stt = clock();
    x        = mNN.colPivHouseholderQr().solve(v_Nd);
    cout << "time of QR decomposition is " << 1000 * (clock() - time_stt) / static_cast<double>(CLOCKS_PER_SEC) << "ms"
         << endl;
    cout << "x = " << x.transpose() << endl;

    // cholesky decomposition
    time_stt = clock();
    x        = mNN.ldlt().solve(v_Nd);
    cout << "time of ldlt decomposition is " << 1000 * (clock() - time_stt) / static_cast<double>(CLOCKS_PER_SEC)
         << "ms" << endl;
    cout << "x = " << x.transpose() << endl;
}
}  // namespace slamdunk