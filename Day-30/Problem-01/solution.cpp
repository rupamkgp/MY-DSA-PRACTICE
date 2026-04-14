#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        for (int n : nums) {
            int temp = max(rob1 + n, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    Solution sol;
    cout << sol.rob(nums) << endl; // Expected: 4
    return 0;
}
