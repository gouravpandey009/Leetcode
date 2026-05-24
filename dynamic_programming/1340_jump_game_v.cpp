#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int dfs(int index,
            vector<int>& arr,
            int d,
            vector<int>& dp) {

        if (dp[index] != -1) {
            return dp[index];
        }

        int n = arr.size();

        int ans = 1;

        for (int j = index - 1;
             j >= max(0, index - d);
             j--) {

            if (arr[j] >= arr[index]) {
                break;
            }

            ans = max(ans,
                      1 + dfs(j, arr, d, dp));
        }

        for (int j = index + 1;
             j <= min(n - 1, index + d);
             j++) {

            if (arr[j] >= arr[index]) {
                break;
            }

            ans = max(ans,
                      1 + dfs(j, arr, d, dp));
        }

        return dp[index] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();

        vector<int> dp(n, -1);

        int ans = 1;

        for (int i = 0; i < n; i++) {

            ans = max(ans,
                      dfs(i, arr, d, dp));
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> arr = {6,4,14,6,8,13,9,7,10,6,12};

    int d = 2;

    cout << obj.maxJumps(arr, d);

    return 0;
}