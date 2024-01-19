#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral_number_HB;
        if (matrix.empty() || matrix[0].empty()) {
            return spiral_number_HB; // Empty matrix case
        }

        int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                spiral_number_HB.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                spiral_number_HB.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    spiral_number_HB.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    spiral_number_HB.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return spiral_number_HB;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<int> result = solution.spiralOrder(matrix);

    cout << "Spiral Order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
