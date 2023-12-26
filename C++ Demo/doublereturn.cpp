#include <iostream>

template <typename T1, typename T2>
double floatingPointDivide(const T1& numerator, const T2& denominator) {
    // Ensure that both numerator and denominator can be converted to double
    double num = static_cast<double>(numerator);
    double denom = static_cast<double>(denominator);

    if (denom == 0) {
        std::cerr << "Error: Division by zero." << std::endl;
        return 0.0; // You can choose to handle division by zero differently
    }

    return num / denom;
}

int main() {
    int num1 = 10;
    int num2 = 3;

    double result = floatingPointDivide(num1, num2);
    std::cout << "Result: " << result << std::endl;

    float num3 = 5.0f;
    double num4 = 2.0;

    result = floatingPointDivide(num3, num4);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
