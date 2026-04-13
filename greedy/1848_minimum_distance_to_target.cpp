#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int getMinDistance(vector<int>& nums, int target, int start) {
    int ans = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            ans = min(ans, abs(i - start));
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    int target = 5, start = 3;

    cout << getMinDistance(nums, target, start) << endl; 
}