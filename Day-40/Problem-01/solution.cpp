#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    Solution sol;
    cout << sol.canJump(nums) << endl; // Expected: 1
    return 0;
}
