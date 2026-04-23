#include <bits/stdc++.h>
using namespace std;

vector<long long> distance(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, vector<int>> mp;

    for(int i = 0; i < n; i++) {
        mp[nums[i]].push_back(i);
    }

    vector<long long> ans(n, 0);

    for(auto &it : mp) {
        vector<int> &idx = it.second;
        int k = idx.size();

        vector<long long> prefix(k + 1, 0);
        for(int i = 0; i < k; i++) {
            prefix[i + 1] = prefix[i] + idx[i];
        }

        for(int i = 0; i < k; i++) {
            long long left = (long long)i * idx[i] - prefix[i];
            long long right = (prefix[k] - prefix[i]) - (long long)(k - i) * idx[i];
            ans[idx[i]] = left + right;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1,3,1,1,2};

    vector<long long> res = distance(nums);

    for(auto x : res) cout << x << " ";
    cout << endl;

    return 0;
}