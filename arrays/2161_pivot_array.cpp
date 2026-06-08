#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int> less;
        vector<int> equal;
        vector<int> greater;

        for (int num : nums) {

            if (num < pivot)
                less.push_back(num);

            else if (num == pivot)
                equal.push_back(num);

            else
                greater.push_back(num);
        }

        vector<int> result;

        result.insert(result.end(), less.begin(), less.end());
        result.insert(result.end(), equal.begin(), equal.end());
        result.insert(result.end(), greater.begin(), greater.end());

        return result;
    }
};

int main() {

    vector<int> nums = {9,12,5,10,14,3,10};
    int pivot = 10;

    Solution obj;

    vector<int> ans = obj.pivotArray(nums, pivot);

    for (int x : ans)
        cout << x << " ";

    return 0;
}