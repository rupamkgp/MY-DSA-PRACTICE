#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
    stack<TreeNode*> st;
    void pushAllLeft(TreeNode* node) {
        for (; node != nullptr; st.push(node), node = node->left);
    }
public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    int next() {
        TreeNode* tmpNode = st.top();
        st.pop();
        pushAllLeft(tmpNode->right);
        return tmpNode->val;
    }
    bool hasNext() {
        return !st.empty();
    }
};

int main() {
    return 0;
}
