#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        while (n > 0) {
            count += n & 1;
            n >>= 1;
        }
        
        return count;
    }
};

int main() {
    Solution solution;

    // Test cases
    uint32_t input1 = 0b00000000000000000000000000001011;
    uint32_t input2 = 0b00000000000000000000000010000000;
    uint32_t input3 = 0b11111111111111111111111111111101;

    cout << solution.hammingWeight(input1) << endl;  // Output: 3
    cout << solution.hammingWeight(input2) << endl;  // Output: 1
    cout << solution.hammingWeight(input3) << endl;  // Output: 31

    return 0;
}
