#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    int digitSum(int num) {

        int sum = 0;

        while (num > 0) {

            sum += num % 10;

            num /= 10;
        }

        return sum;
    }

    int minElement(vector<int>& nums) {

        int ans = INT_MAX;

        for (int num : nums) {

            ans = min(ans,
                      digitSum(num));
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums =
        {10, 12, 13, 14};

    cout << obj.minElement(nums);

    return 0;
}