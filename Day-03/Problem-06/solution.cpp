#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for(int num : st)
        {
            if(!st.count(num - 1))
            {
                int current = num;
                int length = 1;

                while(st.count(current + 1))
                {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    
    Solution sol;

    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Example 1 Output: " << sol.longestConsecutive(nums1) << endl;

    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Example 2 Output: " << sol.longestConsecutive(nums2) << endl;

    vector<int> nums3 = {1, 0, 1, 2};
    cout << "Example 3 Output: " << sol.longestConsecutive(nums3) << endl;

    return 0;
}
