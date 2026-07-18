class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        vector<int> sorted = nums;

        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> firstIndex;

        for (int i = 0; i < sorted.size(); i++) {

            if (!firstIndex.count(sorted[i]))
                firstIndex[sorted[i]] = i;
        }

        vector<int> answer;

        for (int x : nums)
            answer.push_back(firstIndex[x]);

        return answer;
    }
};