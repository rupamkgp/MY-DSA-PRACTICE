#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    // Brute Force Approach
    // Time Complexity: O(N log N) - due to set insertion
    // Space Complexity: O(N) - to store unique elements in the set
    int removeDuplicatesBrute(vector<int>& nums) {
        set<int> uniqueElements;
        for (int i = 0; i < nums.size(); ++i) {
            uniqueElements.insert(nums[i]);
        }
        
        int k = 0;
        for (auto it : uniqueElements) {
            nums[k] = it;
            k++;
        }
        return k;
    }

    // Optimal Approach: Two Pointers
    // Time Complexity: O(N) - single pass through the array
    // Space Complexity: O(1) - modified in-place
    int removeDuplicatesOptimal(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        int i = 0; // Pointer to the last unique element
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1; // Number of unique elements is index + 1
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    
    int k = sol.removeDuplicatesOptimal(nums);
    
    cout << "Number of unique elements: " << k << "\n";
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";

    return 0;
}
