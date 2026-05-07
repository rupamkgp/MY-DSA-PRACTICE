#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    void backtrack(vector<string>& ans, string curr, int open, int close, int max_p) {
        if (curr.length() == max_p * 2) {
            ans.push_back(curr);
            return;
        }
        if (open < max_p) backtrack(ans, curr + "(", open + 1, close, max_p);
        if (close < open) backtrack(ans, curr + ")", open, close + 1, max_p);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }
};

int main() {
    Solution sol;
    auto res = sol.generateParenthesis(2);
    for (auto& s : res) cout << s << " "; // Expected: (()) ()()
    cout << endl;
    return 0;
}
