#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    // Brute Force Approach
    // Time Complexity: O(n^3) - testing all possible triplets
    // Space Complexity: O(1) - no extra space
    int threeSumClosestBrute(vector<int>& nums, int target) {
        int n = nums.size();
        int closestSum = 1e5; // Use a large number
        
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    int currentSum = nums[i] + nums[j] + nums[k];
                    if (abs(currentSum - target) < abs(closestSum - target)) {
                        closestSum = currentSum;
                    }
                }
            }
        }
        return closestSum;
    }

    // Optimal Approach: Sorting + Two Pointers
    // Time Complexity: O(n log n) + O(n^2) = O(n^2)
    // Space Complexity: O(1) or O(log n) depending on the sorting algorithm
    int threeSumClosestOptimal(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closestSum = 1e5;

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }

                if (currentSum > target) {
                    right--;
                } else if (currentSum < target) {
                    left++;
                } else {
                    return currentSum; // Perfect match
                }
            }
        }
        return closestSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    
    cout << "Optimal Approach: " << sol.threeSumClosestOptimal(nums, target) << endl;

    return 0;
}
