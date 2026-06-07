#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void backtrack(int n, int k, int start, vector<int>& curr, vector<vector<int>>& ans) {
        if ((int)curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            backtrack(n, k, i + 1, curr, ans);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(n, k, 1, curr, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    auto res = sol.combine(4, 2);
    cout << res.size() << endl; // Expected: 6
    return 0;
}
