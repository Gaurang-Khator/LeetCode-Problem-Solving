class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // int n = nums1.size();
        // vector<int> res(n);
        // unordered_map<int, int> mp;
        // for(int i=0; i<nums2.size(); i++){
        //     mp[nums2[i]] = i;
        // }
        // for(int i=0; i<nums1.size(); i++) {
        //     int idx = mp[nums1[i]];
        //     stack<int> st;
        //     for(int j=nums2.size()-1; j>= idx; j--) {
        //         while(!st.empty() && st.top()<nums2[j]) st.pop();
        //         res[i] = st.empty() ? -1 : st.top();
        //         st.push(nums2[j]);
        //     }
        // }
        // return res;
        stack<int> st;
        unordered_map<int, int> mp;
        for(int i=nums2.size()-1; i>=0; i--) {
            while(!st.empty() && st.top() < nums2[i]) st.pop();
            mp[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        vector<int> res;
        for(int i=0; i<nums1.size(); i++) {
            res.push_back(mp[nums1[i]]);
        }
        return res;
    }
};