#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Time Complexity: O(N) where N is the length of nums (one pass mapping)
    // Space Complexity: O(N) for storing elements in the hashmap
    vector<int> twoSum(vector<int>& nums, int target) { 
        unordered_map<int,int> mp;
        
        for(int i = 0; i < nums.size(); i++){
            // Value needed to hit the target
            int need = target - nums[i];

            // If the needed value is already in the map, return indices
            if(mp.count(need)){
                return {mp[need], i};
            }

            // Otherwise, store current element's value and index into the map
            mp[nums[i]] = i;
        }
        
        return {}; // Return empty array if not found (problem guarantees one answer)
    }
};
