#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int maxDigit = 0;
        for(char c : n) {
            maxDigit = max(maxDigit, c - '0');
        }
        return maxDigit;
    }
};

int main() {
    Solution sol;
    string input;

    cout << "--- Partitioning Into Minimum Number Of Deci-Binary Numbers ---" << endl;
    cout << "Enter a large number (or 'exit' to quit): ";

    while (cin >> input && input != "exit") {
        int result = sol.minPartitions(input);
        
        cout << "Minimum partitions required: " << result << endl;
        cout << "\nEnter another number: ";
    }

    return 0;
}
