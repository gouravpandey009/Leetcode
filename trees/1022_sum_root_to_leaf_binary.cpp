#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int curr) {
        if (!node) return 0;

        // Build binary number: shift left and add current bit
        curr = (curr << 1) | node->val;

        // If leaf node, return the path value
        if (!node->left && !node->right)
            return curr;

        return dfs(node->left, curr) + dfs(node->right, curr);
    }
};

// Helper: Build a tree from a level-order vector
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return NULL;
    
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();
        
        // Left Child
        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;
        
        // Right Child
        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    Solution sol;

    // Example 1: root = [1,0,1,0,1,0,1]
    // Binary paths: 100(4), 101(5), 110(6), 111(7) -> Sum = 22
    vector<int> testCase1 = {1, 0, 1, 0, 1, 0, 1};
    TreeNode* root1 = buildTree(testCase1);
    cout << "Example 1 Result: " << sol.sumRootToLeaf(root1) << " (Expected: 22)" << endl;

    // Example 2: root = [0]
    vector<int> testCase2 = {0};
    TreeNode* root2 = buildTree(testCase2);
    cout << "Example 2 Result: " << sol.sumRootToLeaf(root2) << " (Expected: 0)" << endl;

    return 0;
}
