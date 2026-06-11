#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    void backtrack(const string& s, int start, vector<string>& curr, vector<vector<string>>& ans) {
        if (start == (int)s.length()) {
            ans.push_back(curr);
            return;
        }
        for (int i = start; i < (int)s.length(); i++) {
            if (isPalindrome(s, start, i)) {
                curr.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1, curr, ans);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        backtrack(s, 0, curr, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    auto res = sol.partition("aab");
    cout << res.size() << endl; // Expected: 2 ( ["a","a","b"], ["aa","b"] )
    return 0;
}
