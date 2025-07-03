class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int l = -1, r = -1;
        int cnt = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > right) {
                l = i;
            }
            else if(nums[i] >= left && nums[i] <= right) {
                r = i;
            }
            cnt += max(0, r-l);
        }
        return cnt;
    }
};