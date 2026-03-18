#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Brute Force Approach
    // Time Complexity: O(n^2) - check every possible pair
    // Space Complexity: O(1) - no extra space used
    vector<int> twoSumBrute(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }

    // Better / Optimal Approach: Hash Map
    // Time Complexity: O(n) - iterate through the array once (unordered_map lookup is O(1) avg)
    // Space Complexity: O(n) - storing elements in the hash map
    vector<int> twoSumOptimal(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // If complement exists in map, return the pair of indices
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            // Otherwise, add current number and its index to map
            numMap[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSumOptimal(nums, target);
    if (!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]\n";
    }

    return 0;
}
