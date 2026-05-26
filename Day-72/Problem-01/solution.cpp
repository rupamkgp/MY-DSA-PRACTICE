#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const vector<int>& p1, const vector<int>& p2) {
            return p1[0]*p1[0] + p1[1]*p1[1] < p2[0]*p2[0] + p2[1]*p2[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> maxHeap(comp);
        for (auto& p : points) {
            maxHeap.push(p);
            if ((int)maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            ans.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    Solution sol;
    auto res = sol.kClosest(points, 1);
    cout << res[0][0] << " " << res[0][1] << endl; // Expected: -2 2
    return 0;
}
