#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int helper(TreeNode* node, int currSum) {
        if (!node) return 0;
        currSum = currSum * 10 + node->val;
        if (!node->left && !node->right) return currSum;
        return helper(node->left, currSum) + helper(node->right, currSum);
    }
public:
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution sol;
    cout << sol.sumNumbers(root) << endl; // Expected: 25 ( 12 + 13 )
    return 0;
}
