#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool check(vector<int>& nums) {

        int n = nums.size();

        int drops = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] > nums[(i + 1) % n]) {
                drops++;
            }

            if (drops > 1) {
                return false;
            }
        }

        return true;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {3, 4, 5, 1, 2};

    if (obj.check(nums)) {
        cout << "True";
    }
    else {
        cout << "False";
    }

    return 0;
}