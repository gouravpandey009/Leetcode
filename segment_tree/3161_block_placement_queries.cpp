#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class SegmentTree {
public:
    int n;
    vector<int> tree;

    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = value;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid) {
            update(node * 2, start, mid, idx, value);
        } else {
            update(node * 2 + 1, mid + 1, end, idx, value);
        }

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int start, int end, int left, int right) {
        if (right < start || end < left) {
            return 0;
        }

        if (left <= start && end <= right) {
            return tree[node];
        }

        int mid = (start + end) / 2;

        return max(
            query(node * 2, start, mid, left, right),
            query(node * 2 + 1, mid + 1, end, left, right)
        );
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        int LIMIT = 50000;

        set<int> obstacles;

        obstacles.insert(0);
        obstacles.insert(LIMIT);

        SegmentTree seg(LIMIT + 1);

        seg.update(1, 0, LIMIT, LIMIT, LIMIT);

        vector<bool> answer;

        for (auto& q : queries) {

            if (q[0] == 1) {

                int x = q[1];

                auto rightIt = obstacles.lower_bound(x);

                int nextObstacle = *rightIt;
                int prevObstacle = *prev(rightIt);

                obstacles.insert(x);

                seg.update(1, 0, LIMIT, x, x - prevObstacle);

                seg.update(1, 0, LIMIT, nextObstacle, nextObstacle - x);
            }
            else {

                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);

                int prevObstacle = *prev(it);

                int maxGap =
                    seg.query(1, 0, LIMIT, 0, prevObstacle);

                maxGap =
                    max(maxGap, x - prevObstacle);

                answer.push_back(maxGap >= sz);
            }
        }

        return answer;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> queries = {
        {1, 7},
        {2, 10, 5},
        {2, 10, 8}
    };

    vector<bool> ans = obj.getResults(queries);

    for (bool x : ans) {
        cout << (x ? "true" : "false") << " ";
    }

    return 0;
}