#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    vector<string> mappings = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtrack(string& digits, int idx, string curr, vector<string>& ans) {
        if (idx == (int)digits.length()) {
            ans.push_back(curr);
            return;
        }
        string letters = mappings[digits[idx] - '0'];
        for (char c : letters) {
            backtrack(digits, idx + 1, curr + c, ans);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> ans;
        backtrack(digits, 0, "", ans);
        return ans;
    }
};

int main() {
    Solution sol;
    auto res = sol.letterCombinations("23");
    cout << res.size() << endl; // Expected: 9
    return 0;
}
