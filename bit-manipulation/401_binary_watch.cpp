#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countBits(int x) {
        int cnt = 0;
        while(x) {
            cnt += x & 1;
            x >>= 1;
        }
        return cnt;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;

        for(int h = 0; h < 12; h++) {
            for(int m = 0; m < 60; m++) {
                if(countBits(h) + countBits(m) == turnedOn) {
                    string time = to_string(h) + ":";
                    if(m < 10) time += "0";
                    time += to_string(m);
                    res.push_back(time);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    int turnedOn = 1;
    vector<string> result = sol.readBinaryWatch(turnedOn);

    cout << "Possible times for " << turnedOn << " LEDs:" << endl;
    for (const string& s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
