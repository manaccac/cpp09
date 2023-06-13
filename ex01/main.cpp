#include "RPN.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: RPN \"expression\"\n";
        return 1;
    }
    RPN rpn;
    try {
        std::cout << rpn.calculate(argv[1]) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
