class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        unordered_set<int> ans;

        for (int num : nums1) {
            st.insert(num);
        }

        for (int num : nums2) {
            if (st.find(num) != st.end()) {
                ans.insert(num);
            }
        }

        return vector<int>(ans.begin(), ans.end());
    }
};