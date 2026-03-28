#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long n_sq = (long long)n * n;
        long long sum = n_sq * (n_sq + 1) / 2;
        long long sq_sum = n_sq * (n_sq + 1) * (2 * n_sq + 1) / 6;
        
        long long grid_sum = 0, grid_sq_sum = 0;
        for (auto& row : grid) {
            for (int val : row) {
                grid_sum += val;
                grid_sq_sum += (long long)val * val;
            }
        }
        
        long long diff = grid_sum - sum; // a - b
        long long sq_diff = grid_sq_sum - sq_sum; // a^2 - b^2
        long long sum_ab = sq_diff / diff; // a + b
        
        int a = (diff + sum_ab) / 2;
        int b = (sum_ab - diff) / 2;
        return {a, b};
    }
};

int main() {
    return 0;
}
