#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    // Brute Force Approach
    // Time Complexity: O(n^3 * log(number of unique triplets)) - 3 loops and set insertion
    // Space Complexity: O(number of unique triplets) - using a set
    vector<vector<int>> threeSumBrute(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        return vector<vector<int>>(st.begin(), st.end());
    }

    // Better Approach
    // Time Complexity: O(n^2 * log(number of unique triplets)) - 2 loops and hashset lookups/insertion
    // Space Complexity: O(n) + O(number of unique triplets)
    vector<vector<int>> threeSumBetter(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++) {
            set<int> hashSet;
            for (int j = i + 1; j < n; j++) {
                int third = -(nums[i] + nums[j]);
                if (hashSet.find(third) != hashSet.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[j]);
            }
        }
        return vector<vector<int>>(st.begin(), st.end());
    }

    // Optimal Approach: Sorting + Two Pointers
    // Time Complexity: O(n log n) + O(n^2) = O(n^2)
    // Space Complexity: O(no. of unique triplets) for the result
    vector<vector<int>> threeSumOptimal(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            // Remove duplicates for the 'i' pointer
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    // Remove duplicates for the 'j' and 'k' pointers
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    
    vector<vector<int>> ans = sol.threeSumOptimal(nums);
    cout << "Triplets summing, to 0 are: \n";
    for (auto it : ans) {
        cout << "[ ";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";

    return 0;
}
