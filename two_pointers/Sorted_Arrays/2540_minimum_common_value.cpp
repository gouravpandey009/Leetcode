#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int i = 0;
        int j = 0;

        int n = nums1.size();
        int m = nums2.size();

        while (i < n && j < m) {

            if (nums1[i] == nums2[j]) {
                return nums1[i];
            }

            if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        return -1;
    }
};

int main() {

    Solution obj;

    vector<int> nums1 = {1, 2, 3, 6};
    vector<int> nums2 = {2, 3, 4, 5};

    cout << obj.getCommon(nums1, nums2);

    return 0;
}