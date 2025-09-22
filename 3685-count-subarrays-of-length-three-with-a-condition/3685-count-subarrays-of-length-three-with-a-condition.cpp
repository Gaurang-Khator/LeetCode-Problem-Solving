class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int l = 0, r = 0, cnt = 0;

        while(r < nums.size()) {
            if(r-l+1 == 3) {
                if((nums[l]+nums[r])*2 == nums[(l+r)/2]) cnt++;
                l++;
            }
            r++;
        }

        return cnt;
    }
};