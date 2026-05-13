#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int l = 0, r = nums.size() - 1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                ans = mid;
                if (isFirst) r = mid - 1;
                else l = mid + 1;
            } else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findBound(nums, target, true), findBound(nums, target, false)};
    }
};

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    Solution sol;
    auto res = sol.searchRange(nums, 8);
    cout << res[0] << " " << res[1] << endl; // Expected: 3 4
    return 0;
}
