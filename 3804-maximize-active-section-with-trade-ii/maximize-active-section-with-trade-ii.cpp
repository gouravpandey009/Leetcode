class SegmentTree {
    int n;
    vector<int> tree;

    void build(int node, int l, int r, vector<int> &a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }

        int mid = (l + r) >> 1;

        build(node << 1, l, mid, a);
        build(node << 1 | 1, mid + 1, r, a);

        tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) >> 1;
        int ans = 0;

        if (ql <= mid)
            ans = max(ans, query(node << 1, l, mid, ql, qr));

        if (qr > mid)
            ans = max(ans, query(node << 1 | 1, mid + 1, r, ql, qr));

        return ans;
    }

public:

    SegmentTree(vector<int> &a) {

        n = a.size();
        tree.assign(4 * max(1, n), 0);

        if (n)
            build(1, 0, n - 1, a);
    }

    int query(int l, int r) {

        if (l > r || n == 0)
            return 0;

        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {

        int totalOne = count(s.begin(), s.end(), '1');

        vector<int> zeroLen;
        vector<int> left;
        vector<int> right;

        int n = s.size();

        for (int i = 0; i < n; ) {

            int j = i;

            while (j < n && s[j] == s[i])
                j++;

            if (s[i] == '0') {
                zeroLen.push_back(j - i);
                left.push_back(i);
                right.push_back(j - 1);
            }

            i = j;
        }

        int m = zeroLen.size();

        if (m < 2)
            return vector<int>(queries.size(), totalOne);

        vector<int> gain(m - 1);

        for (int i = 0; i < m - 1; i++)
            gain[i] = zeroLen[i] + zeroLen[i + 1];

        SegmentTree st(gain);

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int first = lower_bound(right.begin(), right.end(), l) - right.begin();
            int last  = upper_bound(left.begin(), left.end(), r) - left.begin() - 1;

            // Less than two zero blocks.
            if (first >= last || first >= m || last < 0) {
                ans.push_back(totalOne);
                continue;
            }

            int firstLen = right[first] - max(left[first], l) + 1;
            int lastLen  = min(right[last], r) - left[last] + 1;

            if (first + 1 == last) {

                ans.push_back(totalOne + firstLen + lastLen);
                continue;
            }

            int best = 0;

            // First partial block.
            best = max(best, firstLen + zeroLen[first + 1]);

            // Last partial block.
            best = max(best, zeroLen[last - 1] + lastLen);

            // Completely inside.
            best = max(best, st.query(first + 1, last - 2));

            ans.push_back(totalOne + best);
        }

        return ans;
    }
};