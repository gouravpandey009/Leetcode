class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mnOdd = INT_MAX;

        for (int x : nums1) {
            if (x & 1)
                mnOdd = min(mnOdd, x);
        }
        if (mnOdd == INT_MAX)
            return true;

        for (int x : nums1) {
            if ((x & 1) == 0 && x < mnOdd)
                return false;
        }

        return true;
    }
};