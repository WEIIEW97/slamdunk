#include "intro/hello_slam.h"
#include "intro/intro_eigen.h"
#include "intro/coordinate_transform.h"
#include "math/rodrigues.h"
// #include "visualize/plot_trajectory.h"
#include "visualize/visualize_geometry.h"
#include <iostream>
#include <string>

using namespace slamdunk;
int main() {
    RotationMatrix rm;
    TranslationVector tv;
    QuaternionVector qv;

    rm.print();
    tv.print();
    qv.print();
    return 0;
}
