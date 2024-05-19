class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n =nums.size();
        vector<int> parity_check(1, 0);
        for(int i=1, j=0; i<n; i++) {
            if(nums[i]%2 == nums[i-1]%2) {
                j++;
            }
            parity_check.push_back(j);
        }
        vector<bool> ans;
        for(auto q: queries) {
            int l = q[0];
            int r = q[1];
            ans.push_back(parity_check[l] == parity_check[r]);
        }
        return ans;
    }
};