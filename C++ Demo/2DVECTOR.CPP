#include <iostream>

// Define a structure to represent a 2D vector
struct Vector2D {
    double a; // x component
    double b; // y component
};

// Function to calculate the sum of two vectors
Vector2D addVectors(const Vector2D& v1, const Vector2D& v2) {
    Vector2D result;
    result.a = v1.a + v2.a;
    result.b = v1.b + v2.b;
    return result;
}

// Function to calculate the difference between two vectors
Vector2D subtractVectors(const Vector2D& v1, const Vector2D& v2) {
    Vector2D result;
    result.a = v1.a - v2.a;
    result.b = v1.b - v2.b;
    return result;
}

int main() {
    Vector2D vector1, vector2, sum, difference;

    // Input vector1
    std::cout << "Enter the components of vector1 (a b): ";
    std::cin >> vector1.a >> vector1.b;

    // Input vector2
    std::cout << "Enter the components of vector2 (a b): ";
    std::cin >> vector2.a >> vector2.b;

    // Calculate the sum of vectors
    sum = addVectors(vector1, vector2);

    // Calculate the difference of vectors
    difference = subtractVectors(vector1, vector2);

    // Display the results
    std::cout << "Vector1 + Vector2 = (" << sum.a << ", " << sum.b << ")" << std::endl;
    std::cout << "Vector1 - Vector2 = (" << difference.a << ", " << difference.b << ")" << std::endl;

    return 0;
}
