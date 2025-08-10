#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string buffer;
    std::cout << "Enter a calculation in the format <number-1><operation><number-2>: ";
    std::getline(std::cin, buffer);

    std::stringstream buffer_stream(buffer);
    double a, b;
    char operation;


    buffer_stream >> a >> operation >> b;


    double result;
    switch (operation) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b != 0) {
                result = a / b;
            } else {
                std::cout << "Error: Division by zero!" << std::endl;
                return 1;
            }
            break;
        default:
            std::cout << "Error: Invalid operation!" << std::endl;
            return 1;
    }


    std::cout << "Result: " << result << std::endl;

    return 0;
}