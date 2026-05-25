#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for (int n : nums) {
            add(n);
        }
    }
    int add(int val) {
        minHeap.push(val);
        if ((int)minHeap.size() > size) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kth(3, nums);
    cout << kth.add(3) << endl; // Expected: 4
    return 0;
}
