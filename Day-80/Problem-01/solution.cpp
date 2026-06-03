#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& curr, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        for (int i = start; i < (int)candidates.size(); i++) {
            if (candidates[i] <= target) {
                curr.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], i, curr, ans);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(candidates, target, 0, curr, ans);
        return ans;
    }
};

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    Solution sol;
    auto res = sol.combinationSum(candidates, 7);
    cout << res.size() << endl; // Expected: 2 ( [2,2,3], [7] )
    return 0;
}
