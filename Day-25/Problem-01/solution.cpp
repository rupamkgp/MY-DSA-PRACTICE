#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;
        while (curr->next) {
            if (curr->next->val == val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    Solution sol;
    ListNode* res = sol.removeElements(head, 2);
    cout << res->val << endl; // Expected: 1
    return 0;
}
