class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) {
            return vector<int>();
        }
        
        unordered_set<int> set(nums1.begin(), nums1.end());
        unordered_set<int> ans;
        
        for (int num : nums2) {
            if (set.find(num) != set.end()) {
                ans.insert(num);
            }
        }
        
        return vector<int>(ans.begin(), ans.end());
    }
};