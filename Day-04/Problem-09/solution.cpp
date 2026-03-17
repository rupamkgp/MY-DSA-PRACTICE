class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        
        // Count nums1
        for (int x : nums1) {
            freq[x]++;
        }
        
        vector<int> result;
        
        // Match with nums2
        for (int x : nums2) {
            if (freq[x] > 0) {
                result.push_back(x);
                freq[x]--;
            }
        }
        
        return result;
    }
};
