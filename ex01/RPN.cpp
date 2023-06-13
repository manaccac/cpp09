#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <stdexcept>

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &s_RPN) {
	*this = s_RPN;
}
RPN &RPN::operator=(RPN const &s_RPN) {
	if (this != &s_RPN) {
	}
	return *this;
}

float applyOperator(const char op, float b, float a) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: throw std::runtime_error("Invalid operator");
    }
}

float RPN::calculate(const std::string& expression) {
    std::stack<float> stack;
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                throw std::runtime_error("Not enough operands");
            }
            float right_operand = stack.top(); stack.pop();
            float left_operand = stack.top(); stack.pop();
            stack.push(applyOperator(token[0], right_operand, left_operand));
        } else { // Assume it's a number
            stack.push(std::stof(token));
        }
    }
    if (stack.size() != 1) {
        throw std::runtime_error("Invalid expression");
    }
    return stack.top();
}
