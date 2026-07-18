class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        vector<int> frequency(101, 0);

        // Count frequency of every value
        for (int number : nums)
            frequency[number]++;

        // Prefix sum
        for (int i = 1; i <= 100; i++)
            frequency[i] += frequency[i - 1];

        vector<int> answer;

        for (int number : nums) {

            if (number == 0)
                answer.push_back(0);
            else
                answer.push_back(frequency[number - 1]);
        }

        return answer;
    }
};