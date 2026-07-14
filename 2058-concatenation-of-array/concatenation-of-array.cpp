class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        int n = nums.size();

        // Result array of size 2n
        vector<int> answer(2 * n);

        // Copy original array
        for (int i = 0; i < n; i++) {
            answer[i] = nums[i];
        }

        // Copy it again
        for (int i = 0; i < n; i++) {
            answer[i + n] = nums[i];
        }

        return answer;
    }
};