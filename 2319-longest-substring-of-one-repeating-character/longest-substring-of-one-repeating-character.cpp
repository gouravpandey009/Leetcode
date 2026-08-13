class Solution {
    struct Node {
        int len = 0;
        int pref = 0;
        int suff = 0;
        int best = 0;
        char left = 0;
        char right = 0;
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;

        res.left = a.left;
        res.right = b.right;

        res.pref = a.pref;
        res.suff = b.suff;
        res.best = max(a.best, b.best);

        if (a.right == b.left) {
            res.best = max(res.best, a.suff + b.pref);

            if (a.pref == a.len)
                res.pref = a.len + b.pref;

            if (b.suff == b.len)
                res.suff = b.len + a.suff;
        }

        return res;
    }

    void build(int u, int l, int r) {
        if (l == r) {
            tree[u] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }

        int mid = (l + r) >> 1;

        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);

        tree[u] = merge(tree[u << 1], tree[u << 1 | 1]);
    }

    void update(int u, int l, int r, int pos, char c) {
        if (l == r) {
            s[pos] = c;
            tree[u] = {1, 1, 1, 1, c, c};
            return;
        }

        int mid = (l + r) >> 1;

        if (pos <= mid)
            update(u << 1, l, mid, pos, c);
        else
            update(u << 1 | 1, mid + 1, r, pos, c);

        tree[u] = merge(tree[u << 1], tree[u << 1 | 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        this->s = s;

        int n = s.size();
        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); ++i) {
            update(1, 0, n - 1,
                   queryIndices[i],
                   queryCharacters[i]);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};