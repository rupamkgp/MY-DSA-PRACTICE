#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *first = &dummy, *second = &dummy;
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;
        return dummy.next;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    Solution sol;
    ListNode* res = sol.removeNthFromEnd(head, 1);
    cout << res->val << endl; // Expected: 1
    return 0;
}
