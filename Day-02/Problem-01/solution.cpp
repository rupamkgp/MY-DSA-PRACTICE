#include <iostream>

using namespace std;

class Solution {
public:
    // Time Complexity: O(log N) where N is the integer (bits processed)
    // Space Complexity: O(1)
    int hammingWeight(int n) {
        int cnt = 0;
        while(n > 0) {
            // Check if the least significant bit is 1
            if((n & 1) != 0) {
                cnt++;
            }
            // Right-shift n by 1 to process the next bit
            n = n >> 1;
        }

        return cnt;
    }
};
