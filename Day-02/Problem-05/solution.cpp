#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // Time Complexity: O(N) where N is the length of the array
    // Space Complexity: O(N) for storing the unique seen elements
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for(int x: nums) {
            // Found duplicate
            if(st.count(x)) {
                return true;
            }

            // Insert unique element
            st.insert(x);
        }
        
        return false;
    }
};
