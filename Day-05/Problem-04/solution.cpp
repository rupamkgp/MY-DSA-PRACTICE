#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Brute Force Approach
    // Time Complexity: O((m+n) log(m+n)) - we add elements and sort
    // Space Complexity: O(1) or O(m+n) depending on the sorting algorithm
    void mergeBrute(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }

    // Optimal Approach: Three Pointers (Starting from the back)
    // Time Complexity: O(m + n) - single pass from back
    // Space Complexity: O(1) - modifying nums1 in-place
    void mergeOptimal(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;     // Pointer for nums1's actual elements
        int j = n - 1;     // Pointer for nums2's elements
        int k = m + n - 1; // Pointer for the end of nums1 (the target position)

        // Merge from the end to avoid overwriting elements in nums1
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    sol.mergeOptimal(nums1, m, nums2, n);
    
    cout << "Merged Array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
