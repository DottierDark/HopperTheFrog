#include <iostream>
#include <cmath>

void logMessage(const std::string& msg) {
    std::cout << "[LOG]: " << msg << std::endl;
}

float calculateDistance(float x1, float y1, float x2, float y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}