#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_good_subsequence(int n, int k, string s) {
    vector<int> letter_count(k, 0);

    for (char letter : s) {
        int index = letter - 'A';
        letter_count[index] += 1;
    }

    int min_frequency = *min_element(letter_count.begin(), letter_count.end());
    int length_of_longest_good_subsequence = min_frequency * k;

    return length_of_longest_good_subsequence;
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int result = longest_good_subsequence(n, k, s);
    cout << result << endl;

    return 0;
}
