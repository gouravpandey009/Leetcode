#include <iostream>
#include <vector>
using namespace std;

int minimumDistance(vector<int>& nums) {
    int n = nums.size();
    int ans = n + 1;

    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] != nums[j]) continue;

            for(int k = j + 1; k < n; k++) {
                if(nums[i] == nums[k]) {
                    ans = min(ans, k - i);
                    break;
                }
            }
        }
    }

    return ans == n + 1 ? -1 : ans * 2;
}

int main() {
    vector<int> nums = {1,2,1,1,3};

    cout << minimumDistance(nums) << endl; // Output: 6
}