#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    void backtrack(TreeNode* node, int sum, vector<int>& curr, vector<vector<int>>& ans) {
        if (!node) return;
        curr.push_back(node->val);
        if (!node->left && !node->right && sum == node->val) {
            ans.push_back(curr);
        } else {
            backtrack(node->left, sum - node->val, curr, ans);
            backtrack(node->right, sum - node->val, curr, ans);
        }
        curr.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(root, targetSum, curr, ans);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    Solution sol;
    auto res = sol.pathSum(root, 3);
    cout << res.size() << endl; // Expected: 1
    return 0;
}
