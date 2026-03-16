#include <iostream>

using namespace std;

class Solution {
public:
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        
        // A power of 2 has only 1 set bit, meaning n & (n - 1) will be 0
        return (n & (n - 1)) == 0;
    }
};
