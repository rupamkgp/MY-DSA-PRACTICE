#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void backtrack(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& ans) {
        ans.push_back(curr);
        for (int i = start; i < (int)nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(nums, i + 1, curr, ans);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(nums, 0, curr, ans);
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2};
    Solution sol;
    auto res = sol.subsets(nums);
    cout << res.size() << endl; // Expected: 4
    return 0;
}
