#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int countDistinctLetters(string& str) {
    unordered_set<char> distinctLetters;

    for (char ch : str) {
        if (isalpha(ch)) {  // Check if the character is a letter
            distinctLetters.insert(ch);
        }
    }

    return distinctLetters.size();
}

int main() {
    string str = "{a, a, a, a}";

    // Extracting the substring between curly brackets
    size_t start = str.find('{');
    size_t end = str.find('}');
    string substring = str.substr(start + 1, end - start - 1);

    int result = countDistinctLetters(substring);

    cout << result << endl;

    return 0;
}
