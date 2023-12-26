#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        // Base case: numRows is 0, return an empty vector
        if (numRows == 0) {
            return result;
        }

        // First row
        result.push_back({1});

        // Generate each row based on the previous row
        for (int i = 1; i < numRows; ++i) {
            vector<int> row;
            // First element is always 1
            row.push_back(1);
            // Calculate the middle elements
            for (int j = 1; j < i; ++j) {
                row.push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
            // Last element is always 1
            row.push_back(1);
            // Add the generated row to the result
            result.push_back(row);
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Test case
    int numRows = 6;
    vector<vector<int>> result = solution.generate(numRows);

    // Output the result
    for (const auto& row : result) {
        cout << "[";
        for (int num : row) {
            cout << num << ",";
        }
        cout << "]" << endl;
    }

    return 0;
}
