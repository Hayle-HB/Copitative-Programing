#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int currentPassengers = 0;  // Current number of passengers inside the tram
    int minCapacity = 0;       // Minimum tram capacity needed

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        // Update the number of passengers inside the tram
        currentPassengers = currentPassengers - a + b;

        // Update the minimum tram capacity needed
        minCapacity = max(minCapacity, currentPassengers);
    }

    cout << minCapacity << endl;

    return 0;
}
