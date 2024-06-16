#include "../include/glfw.hpp"

#include <iostream>

void glfw::PRINT_ON_ERROR(int error, const char *description) {
    std::cerr << "GLFW Error: " << description << std::endl;
}
