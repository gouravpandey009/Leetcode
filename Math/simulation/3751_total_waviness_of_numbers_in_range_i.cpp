#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int getWaviness(int num) {
        string s = to_string(num);
        int wave = 0;

        for (int i = 1; i < (int)s.size() - 1; i++) {
            if (s[i] > s[i - 1] && s[i] > s[i + 1]) {
                wave++;
            }
            else if (s[i] < s[i - 1] && s[i] < s[i + 1]) {
                wave++;
            }
        }
        return wave;
    }

    int totalWaviness(int num1, int num2) {
        int answer = 0;
        for (int num = num1; num <= num2; num++) {
            answer += getWaviness(num);
        }
        return answer;
    }
};

int main() {
    Solution solver;


    int num1 = 100;
    int num2 = 150;


    int result = solver.totalWaviness(num1, num2);
    
    cout << "Total Waviness between " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}
