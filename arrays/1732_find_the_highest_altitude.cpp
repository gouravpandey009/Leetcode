#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int altitude = 0;
        int highest = 0;

        for (int x : gain) {
            altitude += x;
            highest = max(highest, altitude);
        }

        return highest;
    }
};

int main() {

    vector<int> gain = {-5, 1, 5, 0, -7};

    Solution obj;

    cout << obj.largestAltitude(gain) << endl;

    return 0;
}