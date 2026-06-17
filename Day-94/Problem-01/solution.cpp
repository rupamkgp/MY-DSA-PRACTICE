#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    void helper(TreeNode* root, int depth, vector<int>& view) {
        if (!root) return;
        if (depth == (int)view.size()) {
            view.push_back(root->val);
        }
        helper(root->right, depth + 1, view);
        helper(root->left, depth + 1, view);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        helper(root, 0, view);
        return view;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution sol;
    auto res = sol.rightSideView(root);
    cout << res[0] << " " << res[1] << endl; // Expected: 1 3
    return 0;
}
