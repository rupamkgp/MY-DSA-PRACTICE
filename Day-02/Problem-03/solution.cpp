#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Time Complexity: O(N) where N is the length of nums
    // Space Complexity: O(1)
    int missingNumber(vector<int>& nums) {
        int ans = nums.size(); // initialize with n

        // XOR answers with both the index and the value itself from the array
        for(int i = 0 ; i < nums.size(); i++){
            ans ^= i ^ nums[i];
        }
        
        return ans;
    }
};
