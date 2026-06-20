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
    int postIdx;
    TreeNode* build(vector<int>& postorder, int l, int r) {
        if (l > r) return nullptr;
        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inMap[rootVal];
        root->right = build(postorder, mid + 1, r);
        root->left = build(postorder, l, mid - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        inMap.clear();
        for (int i = 0; i < (int)inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        postIdx = postorder.size() - 1;
        return build(postorder, 0, inorder.size() - 1);
    }
};

int main() {
    vector<int> inorder = {2, 1, 3};
    vector<int> postorder = {2, 3, 1};
    Solution sol;
    TreeNode* res = sol.buildTree(inorder, postorder);
    cout << res->val << " " << res->left->val << " " << res->right->val << endl; // Expected: 1 2 3
    return 0;
}
