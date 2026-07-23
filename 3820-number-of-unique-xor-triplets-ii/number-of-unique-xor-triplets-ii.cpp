class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        constexpr int MAXX = 2048;

        vector<char> two(MAXX, 0);
        vector<char> ans(MAXX, 0);

        int n = nums.size();

        // All XOR values of two elements.
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                two[nums[i] ^ nums[j]] = 1;
            }
        }

        // XOR with the third element.
        for (int x = 0; x < MAXX; x++) {

            if (!two[x]) continue;

            for (int v : nums)
                ans[x ^ v] = 1;
        }

        return accumulate(ans.begin(), ans.end(), 0);
    }
};