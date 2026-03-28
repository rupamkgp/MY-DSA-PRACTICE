#include <iostream>
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
    int sum = 0;
    void bstToGstHelper(TreeNode* node) {
        if (!node) return;
        bstToGstHelper(node->right);
        sum += node->val;
        node->val = sum;
        bstToGstHelper(node->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        bstToGstHelper(root);
        return root;
    }
};

int main() {
    return 0;
}
