#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    void backtrack(const string& s, int start, int dots, string curr, vector<string>& ans) {
        if (start == (int)s.length() && dots == 4) {
            ans.push_back(curr.substr(0, curr.length() - 1));
            return;
        }
        if (start == (int)s.length() || dots == 4) return;
        for (int len = 1; len <= 3 && start + len <= (int)s.length(); len++) {
            string part = s.substr(start, len);
            if (part[0] == '0' && len > 1) continue;
            if (stoi(part) <= 255) {
                backtrack(s, start + len, dots + 1, curr + part + ".", ans);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        backtrack(s, 0, 0, "", ans);
        return ans;
    }
};

int main() {
    Solution sol;
    auto res = sol.restoreIpAddresses("25525511135");
    cout << res.size() << endl; // Expected: 2
    return 0;
}
