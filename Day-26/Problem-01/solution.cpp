#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        while (head) {
            vals.push_back(head->val);
            head = head->next;
        }
        int l = 0, r = vals.size() - 1;
        while (l < r) {
            if (vals[l] != vals[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    Solution sol;
    cout << sol.isPalindrome(head) << endl; // Expected: 1
    return 0;
}
