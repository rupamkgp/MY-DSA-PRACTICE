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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        if (count == k) {
            curr = reverseKGroup(curr, k);
            while (count > 0) {
                ListNode* temp = head->next;
                head->next = curr;
                curr = head;
                head = temp;
                count--;
            }
            head = curr;
        }
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    Solution sol;
    ListNode* res = sol.reverseKGroup(head, 2);
    cout << res->val << " " << res->next->val << endl; // Expected: 2 1
    return 0;
}
