#include <iostream>
#include "Cone.h"

/**
 * @brief Считывает параметр конуса с клавиатуры
 * @param reports - строка информации
 * @return 1 при ошибке ввода; при корректном вводе - считанное значение
 * @note Проверяется только на положительность и на то, что введены числа, а не буквы/иное
 */
double getParameter(const std::string reports = "");

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main() {
    double radius = getParameter("Enter radius of the cone base:");
    double height = getParameter("Enter height of the cone:");

    Cone newCone(radius, height); 

    std::cout << "Slant height of cone is " << newCone.getSlantHeight() << std::endl;
    std::cout << "Base area of cone is " << newCone.getBaseArea() << std::endl;
    std::cout << "Lateral surface area of cone is " << newCone.getLateralArea() << std::endl;
    std::cout << "Total surface area of cone is " << newCone.getTotalArea() << std::endl;

    return 0;
}

double getParameter(const std::string report) {
    std::cout << report << std::endl;
    double value = 0;
    std::cin >> value;
    if (std::cin.fail()) {
        std::cout << "Error. You must insert only numbers." << std::endl;
        exit(1);
    }
    return value;
}