#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int robHelper(vector<int>& nums, int start, int end) {
        int rob1 = 0, rob2 = 0;
        for (int i = start; i <= end; i++) {
            int temp = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robHelper(nums, 0, n - 2), robHelper(nums, 1, n - 1));
    }
};

int main() {
    vector<int> nums = {2, 3, 2};
    Solution sol;
    cout << sol.rob(nums) << endl; // Expected: 3
    return 0;
}
