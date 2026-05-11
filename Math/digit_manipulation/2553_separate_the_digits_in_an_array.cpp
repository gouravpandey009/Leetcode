#include <bits/stdc++.h>
using namespace std;

vector<int> separateDigits(vector<int>& nums) {

    vector<int> ans;

    for (int num : nums) {

        vector<int> temp;

        if (num == 0) {
            temp.push_back(0);
        }

        while (num > 0) {
            temp.push_back(num % 10);
            num /= 10;
        }

        reverse(temp.begin(), temp.end());

        for (int digit : temp) {
            ans.push_back(digit);
        }
    }

    return ans;
}

int main() {

    vector<int> nums = {13, 25, 83, 77};

    vector<int> ans = separateDigits(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}