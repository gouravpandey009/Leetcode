#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        // Build the first window
        int windowSum = 0;

        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        int maxSum = windowSum;

        // Slide the window
        for (int i = k; i < nums.size(); i++) {

            // Remove the element leaving the window
            windowSum -= nums[i - k];

            // Add the new element entering the window
            windowSum += nums[i];

            // Update maximum sum
            maxSum = max(maxSum, windowSum);
        }

        // Average = sum / number of elements
        return (double)maxSum / k;
    }
};