#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {

        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);

        vector<int> answer;

        for (int num : nums) {

            rightSum -= num;

            answer.push_back(abs(leftSum - rightSum));

            leftSum += num;
        }

        return answer;
    }
};

int main() {

    vector<int> nums = {10, 4, 8, 3};

    Solution obj;

    vector<int> ans = obj.leftRigthDifference(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}