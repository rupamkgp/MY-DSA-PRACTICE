#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    // Brute Force Approach
    // Time Complexity: O(N log N) - due to sorting
    // Space Complexity: O(1) or O(N) depending on the sorting algorithm
    vector<int> sortedSquaresBrute(vector<int>& nums) {
        vector<int> sq(nums.begin(), nums.end());
        for (int i = 0; i < sq.size(); i++) {
            sq[i] = sq[i] * sq[i];
        }
        sort(sq.begin(), sq.end());
        return sq;
    }

    // Optimal Approach: Two Pointers
    // Time Complexity: O(N) - single pass through the array
    // Space Complexity: O(N) - to store the resultant array
    vector<int> sortedSquaresOptimal(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0;
        int right = n - 1;
        int index = n - 1;

        while (left <= right) {
            int leftSq = nums[left] * nums[left];
            int rightSq = nums[right] * nums[right];

            if (leftSq > rightSq) {
                result[index] = leftSq;
                left++;
            } else {
                result[index] = rightSq;
                right--;
            }
            index--;
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-4, -1, 0, 3, 10};

    vector<int> result = sol.sortedSquaresOptimal(nums);
    cout << "Squared Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
