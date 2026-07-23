class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        int n = nums.size();

        // Cannot choose three distinct elements.
        if (n < 3)
            return n;

        int bits = 32 - __builtin_clz(n);

        // All values in [0, 2^bits - 1] are achievable.
        return 1 << bits;
    }
};