#include <iostream>
#include <cmath>
#include "Cone.h"


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Cone::Cone(const double radius, const double height) {
    if (radius <= 0 || height <= 0) {
        std::cout << "Error. Radius and height must be positive." << std::endl;
        exit(1);
    }
    this->radius = radius;
    this->height = height;
}

double Cone::getSlantHeight() const {
    return sqrt(pow(radius, 2) + pow(height, 2));
}

double Cone::getBaseArea() const {
    return M_PI * pow(radius, 2);
}

double Cone::getLateralArea() const {
    double l = getSlantHeight();
    return M_PI * radius * l;
}

double Cone::getTotalArea() const {
    return getBaseArea() + getLateralArea();
}