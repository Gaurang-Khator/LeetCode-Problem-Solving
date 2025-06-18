class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        int longest = 0;
        for(auto i: st) {
            int len = 1;
            int temp = i;
            while(st.find(temp+1) != st.end() && st.find(i-1) == st.end()) {
                len++;
                temp++;
            }
            longest = max(len, longest);
        }
        return longest;
    }
};