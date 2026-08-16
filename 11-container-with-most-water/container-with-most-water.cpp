class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int ans = 0;

        while (left < right) {

            // Calculate width
            int width = right - left;

            // Water height is the smaller line
            int h = min(height[left], height[right]);

            // Calculate area
            int area = width * h;

            // Store maximum
            ans = max(ans, area);

            // Move the smaller height
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return ans;
    }
};