#include <iostream>
using namespace std;
 
int main() {
    int n, a, b;
    cin >> n;
    int move;
    while (n--) {
        cin >> a >> b;

        int remainder = a % b;
 
       
        if (remainder != 0) {
            move = b - remainder;
        } else {
            move = 0;
        }
 
        cout << move << endl;
    }
 
    return 0;
}