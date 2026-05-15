#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size(), n = nums2.size();
        int l = 0, r = m;
        while (l <= r) {
            int partitionX = (l + r) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;
            int maxLeftX = (partitionX == 0) ? -2e9 : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? 2e9 : nums1[partitionX];
            int maxLeftY = (partitionY == 0) ? -2e9 : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? 2e9 : nums2[partitionY];
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    return max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                r = partitionX - 1;
            } else {
                l = partitionX + 1;
            }
        }
        return 0.0;
    }
};

int main() {
    vector<int> n1 = {1, 3};
    vector<int> n2 = {2};
    Solution sol;
    cout << sol.findMedianSortedArrays(n1, n2) << endl; // Expected: 2.0
    return 0;
}
