#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int maxDigit = 0;
        for (char c : n) {
            maxDigit = max(maxDigit, c - '0');
            if (maxDigit == 9) return 9;
        }
        return maxDigit;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    string input;

    cout << "Enter a large number (or type 'exit' to quit):" << endl;

    while (cin >> input && input != "exit") {
        int result = sol.minPartitions(input);
        cout << "Minimum partitions for " << input << ": " << result << endl;
        cout << "\nEnter another number: ";
    }

    return 0;
}
