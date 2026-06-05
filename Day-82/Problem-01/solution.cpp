#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& ans) {
        if (start == (int)nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = start; i < (int)nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, ans);
            swap(nums[start], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(nums, 0, ans);
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution sol;
    auto res = sol.permute(nums);
    cout << res.size() << endl; // Expected: 6
    return 0;
}
