#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int initial_zeros = 0;
        for (char c : s)
            if (c == '0') initial_zeros++;

        if (initial_zeros == 0) return 0;

        set<int> unvisited[2];
        for (int i = 0; i <= n; ++i) {
            if (i != initial_zeros)
                unvisited[i % 2].insert(i);
        }

        queue<pair<int, int>> q;
        q.push(make_pair(initial_zeros, 0));

        while (!q.empty()) {

            pair<int, int> curr = q.front();
            int cur = curr.first;
            int steps = curr.second;
            q.pop();

            int min_x = max(0, k - (n - cur));
            int max_x = min(cur, k);

            int L = cur + k - 2 * max_x;
            int R = cur + k - 2 * min_x;
            int parity = abs(L % 2);

            auto it = unvisited[parity].lower_bound(L);
            while (it != unvisited[parity].end() && *it <= R) {
                int next_state = *it;
                if (next_state == 0)
                    return steps + 1;

                q.push(make_pair(next_state, steps + 1));
                unvisited[parity].erase(it++);
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    string s = "110";
    int k = 1;
    cout << sol.minOperations(s, k) << endl;
    return 0;
}
