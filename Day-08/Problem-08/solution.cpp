#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCounts;
        prefixCounts[0] = 1;
        int sum = 0, count = 0;
        for (int num : nums) {
            sum += num;
            if (prefixCounts.find(sum - k) != prefixCounts.end()) {
                count += prefixCounts[sum - k];
            }
            prefixCounts[sum]++;
        }
        return count;
    }
};

int main() {
    return 0;
}
