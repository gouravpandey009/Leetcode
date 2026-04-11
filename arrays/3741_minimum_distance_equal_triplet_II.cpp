#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits> 
using namespace std;

int minimumDistance(vector<int>& nums) {
    unordered_map<int, vector<int>> mp;

    for(int i = 0; i < nums.size(); i++) {
        mp[nums[i]].push_back(i);
    }

    int ans = INT_MAX;

    for(auto &it : mp) {
        vector<int> &idx = it.second;

        if(idx.size() < 3) continue;

        for(int i = 0; i + 2 < idx.size(); i++) {
            ans = min(ans, idx[i+2] - idx[i]);
        }
    }

    return ans == INT_MAX ? -1 : 2 * ans;
}

int main() {
    vector<int> nums = {1,2,1,1,3};

    cout << minimumDistance(nums) << endl; 
}