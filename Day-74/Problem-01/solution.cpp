#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        int maxCount = 0;
        for (char c : tasks) {
            counts[c]++;
            maxCount = max(maxCount, counts[c]);
        }
        int ans = (maxCount - 1) * (n + 1);
        for (auto& entry : counts) {
            if (entry.second == maxCount) ans++;
        }
        return max((int)tasks.size(), ans);
    }
};

int main() {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    Solution sol;
    cout << sol.leastInterval(tasks, 2) << endl; // Expected: 8
    return 0;
}
