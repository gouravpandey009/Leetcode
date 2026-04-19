#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0;
    int n = nums1.size(), m = nums2.size();
    int ans = 0;

    while(i < n && j < m) {
        if(nums1[i] <= nums2[j]) {
            ans = max(ans, j - i);
            j++;
        } else {
            i++;
        }
    }

    return ans;
}

int main() {
    vector<int> nums1 = {55,30,5,4,2};
    vector<int> nums2 = {100,20,10,10,5};

    cout << maxDistance(nums1, nums2) << endl;

    return 0;
}