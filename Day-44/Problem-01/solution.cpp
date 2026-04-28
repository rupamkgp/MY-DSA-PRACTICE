#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = -prices[0];
        int sell = 0;
        for (size_t i = 1; i < prices.size(); i++) {
            buy = max(buy, sell - prices[i]);
            sell = max(sell, buy + prices[i] - fee);
        }
        return sell;
    }
};

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    Solution sol;
    cout << sol.maxProfit(prices, 2) << endl; // Expected: 8
    return 0;
}
