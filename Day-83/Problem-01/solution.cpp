#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    void backtrack(vector<int> nums, int start, vector<vector<int>>& ans) {
        if (start == (int)nums.size() - 1) {
            ans.push_back(nums);
            return;
        }
        for (int i = start; i < (int)nums.size(); i++) {
            if (i != start && nums[i] == nums[start]) continue;
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, ans);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        backtrack(nums, 0, ans);
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 1, 2};
    Solution sol;
    auto res = sol.permuteUnique(nums);
    cout << res.size() << endl; // Expected: 3
    return 0;
}
