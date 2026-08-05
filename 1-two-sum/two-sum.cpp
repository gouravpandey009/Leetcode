class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

    
        unordered_map<int, int> valueToIndex;

        // Process each element exactly once.
        for (int currentIndex = 0; currentIndex < static_cast<int>(nums.size()); ++currentIndex) {

            // Current value under consideration.
            int currentValue = nums[currentIndex];

            // If currentValue + complement = target,
            // then complement = target - currentValue.
            int complement = target - currentValue;

            // Before storing the current value, check whether the required
            // complement has already appeared.
            auto iterator = valueToIndex.find(complement);

            if (iterator != valueToIndex.end()) {

                // The complement already exists.
                // Return its index along with the current index.
                return {iterator->second, currentIndex};
            }

            // Store the current value after checking.
            // This prevents using the same element twice.
            valueToIndex[currentValue] = currentIndex;
        }

        // Problem guarantees an answer.
        // This return is only to satisfy the compiler.
        return {};
    }
};