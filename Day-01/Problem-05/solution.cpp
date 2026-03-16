#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Time Complexity: O(N) where N is the number of elements in nums
    // Space Complexity: O(1)
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        // XOR all elements in the array
        for(int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i]; 
        }
        
        return ans;
    }
};
