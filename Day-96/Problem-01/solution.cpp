#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    unordered_map<int, int> inMap;
    int preIdx;
    TreeNode* build(vector<int>& preorder, int l, int r) {
        if (l > r) return nullptr;
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inMap[rootVal];
        root->left = build(preorder, l, mid - 1);
        root->right = build(preorder, mid + 1, r);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inMap.clear();
        for (int i = 0; i < (int)inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        preIdx = 0;
        return build(preorder, 0, inorder.size() - 1);
    }
};

int main() {
    vector<int> preorder = {1, 2, 3};
    vector<int> inorder = {2, 1, 3};
    Solution sol;
    TreeNode* res = sol.buildTree(preorder, inorder);
    cout << res->val << " " << res->left->val << " " << res->right->val << endl; // Expected: 1 2 3
    return 0;
}
