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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* first = head;
        ListNode* second = head->next;
        first->next = swapPairs(second->next);
        second->next = first;
        return second;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    Solution sol;
    ListNode* res = sol.swapPairs(head);
    cout << res->val << " " << res->next->val << endl; // Expected: 2 1
    return 0;
}
