#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> matrix = {
        {0, 2, 3, 0},
        {5, 6, 7, 8},
        {2, 4, 6, 8},
        {4, 5, 6, 4},
    };

    int raw = matrix.size();
    int col = matrix[0].size();

    vector<int> index;

    for (int i = 0; i < raw; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                index.push_back(i);
                index.push_back(j);
            }
        }
    }

    for (int i = 0; i < index.size(); i += 2) {
        // travel from the zero position to the right
        for (int j = 0; j < col; j++) {
            matrix[index[i]][j] = 0;
        }
        
        // travel from the zero position to the left
        for (int j = 0; j < raw; j++) {
            matrix[j][index[i + 1]] = 0;
        }
    }

    // Print the modified matrix
    for (int i = 0; i < raw; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
