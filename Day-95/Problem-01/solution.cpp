#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> row(sz);
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front(); q.pop();
                int idx = leftToRight ? i : (sz - 1 - i);
                row[idx] = curr->val;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(row);
        }
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution sol;
    auto res = sol.zigzagLevelOrder(root);
    cout << res[0][0] << " " << res[1][0] << " " << res[1][1] << endl; // Expected: 1 3 2
    return 0;
}
