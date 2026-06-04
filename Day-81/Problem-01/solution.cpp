#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& curr, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        for (int i = start; i < (int)candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;
            curr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, curr, ans);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(candidates, target, 0, curr, ans);
        return ans;
    }
};

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    Solution sol;
    auto res = sol.combinationSum2(candidates, 8);
    cout << res.size() << endl; // Expected: 4
    return 0;
}
