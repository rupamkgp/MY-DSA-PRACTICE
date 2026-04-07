#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    Solution sol;
    ListNode* res = sol.deleteDuplicates(head);
    cout << res->val << endl; // Expected: 1
    return 0;
}
