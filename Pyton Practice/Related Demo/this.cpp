#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};

    // Remove elements with value 3
    myVector.erase(std::remove(myVector.begin(), myVector.end(), 3), myVector.end());

    // Display the vector after removal
    for (int i : myVector) {
        std::cout << i << " ";
    }

    return 0;
}
