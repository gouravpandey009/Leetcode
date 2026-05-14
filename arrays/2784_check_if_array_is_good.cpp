#include <bits/stdc++.h>
using namespace std;

bool isGood(vector<int>& nums) {

    int n = nums.size();

    vector<int> freq(n + 1, 0);

    for (int x : nums) {

        if (x > n - 1) return false;

        freq[x]++;
    }

    for (int i = 1; i <= n - 2; i++) {

        if (freq[i] != 1) {
            return false;
        }
    }

    return freq[n - 1] == 2;
}

int main() {

    vector<int> nums = {2, 1, 3, 3};

    if (isGood(nums)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}