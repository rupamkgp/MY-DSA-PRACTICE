#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_water = 0;
        while (left < right) {
            int w = right - left;
            int h = min(height[left], height[right]);
            max_water = max(max_water, w * h);
            if (height[left] < height[right]) left++;
            else right--;
        }
        return max_water;
    }
};

int main() {
    return 0;
}
