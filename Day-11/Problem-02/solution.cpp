#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int minDiff = 1e9;
    int prev = -1;
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (prev != -1) minDiff = min(minDiff, node->val - prev);
        prev = node->val;
        inorder(node->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};

int main() {
    return 0;
}
