#include <bits/stdc++.h>
using namespace std;

vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    int n = nums.size();

    unordered_map<int, vector<int>> mp;
    for(int i = 0; i < n; i++){
        mp[nums[i]].push_back(i);
    }

    vector<int> ans;

    for(int q : queries){
        int val = nums[q];
        auto &v = mp[val];

        if(v.size() == 1){
            ans.push_back(-1);
            continue;
        }

        int res = INT_MAX;

        auto it = lower_bound(v.begin(), v.end(), q);

        if(it != v.end()){
            int j = *it;
            if(j != q){
                int d = abs(j - q);
                res = min(res, min(d, n - d));
            }
        }

        if(it != v.begin()){
            int j = *(it - 1);
            int d = abs(j - q);
            res = min(res, min(d, n - d));
        }

        int first = v[0], last = v.back();

        int d1 = abs(q - first);
        int d2 = abs(q - last);

        res = min(res, min(n - d1, n - d2));

        ans.push_back(res);
    }

    return ans;
}

int main() {
    vector<int> nums = {1,3,1,4,1,3,2};
    vector<int> queries = {0,3,5};

    vector<int> res = solveQueries(nums, queries);

    for(int x : res) cout << x << " ";
}