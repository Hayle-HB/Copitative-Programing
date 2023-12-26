#include <iostream>
#include <cmath>

// Define a template struct to represent a point in 2D space
template <typename T>
struct Point {
    T x;
    T y;
};

// Define a template function to compute the Euclidean distance between two points
template <typename T1, typename T2>
double euclideanDistance(const Point<T1>& p1, const Point<T2>& p2) {
    T1 dx = p1.x - p2.x;
    T1 dy = p1.y - p2.y;
    return std::sqrt(dx * dx + dy * dy);
}

int main() {
    // Instantiate two points with different types
    Point<double> point1 = {1.0, 2.0};
    Point<int> point2 = {4, 6};

    // Compute the Euclidean distance between the points
    double distance = euclideanDistance(point1, point2);

    std::cout << "Euclidean Distance (double vs. int): " << distance << std::endl;

    return 0;
}