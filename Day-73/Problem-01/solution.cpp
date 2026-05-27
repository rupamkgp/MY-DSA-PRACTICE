#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int n : nums) counts[n]++;
        auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);
        for (auto& entry : counts) {
            minHeap.push(entry);
            if ((int)minHeap.size() > k) minHeap.pop();
        }
        vector<int> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().first);
            minHeap.pop();
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    Solution sol;
    auto res = sol.topKFrequent(nums, 2);
    cout << res[0] << " " << res[1] << endl; // Expected: 2 1 (or 1 2)
    return 0;
}
