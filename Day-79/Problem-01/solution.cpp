#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    void backtrack(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& ans) {
        ans.push_back(curr);
        for (int i = start; i < (int)nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            backtrack(nums, i + 1, curr, ans);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(nums, 0, curr, ans);
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 2};
    Solution sol;
    auto res = sol.subsetsWithDup(nums);
    cout << res.size() << endl; // Expected: 6
    return 0;
}
