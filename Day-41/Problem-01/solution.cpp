#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        int jumps = 0, currentEnd = 0, farthest = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
                if (currentEnd >= n - 1) break;
            }
        }
        return jumps;
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    Solution sol;
    cout << sol.jump(nums) << endl; // Expected: 2
    return 0;
}
