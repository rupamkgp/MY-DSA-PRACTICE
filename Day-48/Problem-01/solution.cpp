#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    Solution sol;
    sol.deleteNode(head);
    cout << head->val << endl; // Expected: 2
    return 0;
}
