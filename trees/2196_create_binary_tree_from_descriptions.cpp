#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for (auto &desc : descriptions) {

            int parent = desc[0];
            int child = desc[1];
            int isLeft = desc[2];

            if (!nodes.count(parent))
                nodes[parent] = new TreeNode(parent);

            if (!nodes.count(child))
                nodes[child] = new TreeNode(child);

            if (isLeft)
                nodes[parent]->left = nodes[child];
            else
                nodes[parent]->right = nodes[child];

            children.insert(child);
        }

        for (auto &[value, node] : nodes) {
            if (!children.count(value))
                return node;
        }

        return nullptr;
    }
};

void preorder(TreeNode* root) {
    if (!root) return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {

    vector<vector<int>> descriptions = {
        {20,15,1},
        {20,17,0},
        {15,10,1}
    };

    Solution obj;

    TreeNode* root = obj.createBinaryTree(descriptions);

    cout << "Preorder Traversal: ";
    preorder(root);

    return 0;
}