#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        return nums[l];
    }
};

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    Solution sol;
    cout << sol.findMin(nums) << endl; // Expected: 1
    return 0;
}
