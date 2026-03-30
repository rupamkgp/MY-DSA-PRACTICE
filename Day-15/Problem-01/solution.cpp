#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        
        // Swap left and right subtrees
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        
        return root;
    }
};

void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    // Simple test validation
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    cout << "Original tree (in-order): ";
    printInOrder(root);
    cout << endl;

    Solution sol;
    TreeNode* inverted = sol.invertTree(root);

    cout << "Inverted tree (in-order): ";
    printInOrder(inverted);
    cout << endl; // Expected: 3 2 1

    return 0;
}
