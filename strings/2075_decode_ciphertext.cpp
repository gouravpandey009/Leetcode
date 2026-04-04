#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {

        if(rows == 1) return encodedText;

        int n = encodedText.size();
        int cols = n / rows;

        string result = "";

        for(int j = 0; j < cols; j++) {

            int i = 0, col = j;

            while(i < rows && col < cols) {
                result += encodedText[i * cols + col];
                i++;
                col++;
            }
        }

        while(!result.empty() && result.back() == ' ')
            result.pop_back();

        return result;
    }
};

int main() {

    string s;
    int rows;

    cout << "Enter encoded string: ";
    getline(cin, s);

    cout << "Enter rows: ";
    cin >> rows;

    Solution sol;

    cout << "Decoded string: " 
         << sol.decodeCiphertext(s, rows) << endl;

    return 0;
}