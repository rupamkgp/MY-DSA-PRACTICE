#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(0), dummy2(0);
        ListNode* before = &dummy1;
        ListNode* after = &dummy2;
        while (head) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        after->next = nullptr;
        before->next = dummy2.next;
        return dummy1.next;
    }
};

int main() {
    ListNode* head = new ListNode(2);
    head->next = new ListNode(1);
    Solution sol;
    ListNode* res = sol.partition(head, 2);
    cout << res->val << " " << res->next->val << endl; // Expected: 1 2
    return 0;
}
