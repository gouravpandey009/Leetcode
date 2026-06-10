#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0; =

        int LOG = 32 - __builtin_clz(n);

        vector<vector<int>> mx(n, vector<int>(LOG));
        vector<vector<int>> mn(n, vector<int>(LOG));

        for (int i = 0; i < n; i++) {
            mx[i][0] = nums[i];
            mn[i][0] = nums[i];
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
                mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
            }
        }

        auto getMax = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1);
            return max(mx[l][j], mx[r - (1 << j) + 1][j]);
        };

        auto getMin = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1);
            return min(mn[l][j], mn[r - (1 << j) + 1][j]);
        };

        struct State {
            long long value;
            int l;
            int r;

            bool operator<(const State& other) const {
                return value < other.value;
            }
        };

        priority_queue<State> pq;

        for (int l = 0; l < n; l++) {
            long long val = getMax(l, n - 1) - getMin(l, n - 1);
            pq.push({val, l, n - 1});
        }

        long long answer = 0;

        
        while (k-- > 0 && !pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            answer += cur.value;

            if (cur.r > cur.l) {
                int nr = cur.r - 1;
                long long nextValue = getMax(cur.l, nr) - getMin(cur.l, nr);
                pq.push({nextValue, cur.l, nr});
            }
        }

        return answer;
    }
};

int main() {
    Solution solver;

    vector<int> nums1 = {1, 5, 2, 4, 3};
    int k1 = 3;
    long long result1 = solver.maxTotalValue(nums1, k1);
    cout << "Test Case 1 Result: " << result1 << endl;
    
    vector<int> nums2 = {10, 2, 11, 3};
    int k2 = 2;
    long long result2 = solver.maxTotalValue(nums2, k2);
    cout << "Test Case 2 Result: " << result2 << endl;

    return 0;
}
