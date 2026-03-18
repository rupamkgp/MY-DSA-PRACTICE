#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Brute Force Approach
    // Time Complexity: O(n^2) - Checking all possible pairs
    // Space Complexity: O(1)
    vector<int> twoSumBrute(vector<int>& numbers, int target) {
        vector<int> ans;
        for (int i = 0; i < numbers.size(); ++i) {
            for (int j = i + 1; j < numbers.size(); ++j) {
                if (numbers[i] + numbers[j] == target) {
                    ans.push_back(i + 1);
                    ans.push_back(j + 1);
                    return ans;
                }
            }
        }
        return ans;
    }

    // Better Approach: Binary Search (Since array is sorted)
    // Time Complexity: O(n log n) - For each element, do binary search
    // Space Complexity: O(1)
    vector<int> twoSumBetter(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int left = i + 1, right = numbers.size() - 1;
            int needed = target - numbers[i];
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] == needed) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] < needed) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return {};
    }

    // Optimal Approach: Two Pointers
    // Time Complexity: O(n) - Single pass from both ends
    // Space Complexity: O(1) - modifying in place
    vector<int> twoSumOptimal(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            long long sum = (long long)numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1}; // +1 because output expects 1-indexed array
            } else if (sum > target) {
                right--; // decrease sum
            } else {
                left++; // increase sum
            }
        }
        
        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSumOptimal(numbers, target);
    cout << "Indices: " << result[0] << ", " << result[1] << "\n";

    return 0;
}
