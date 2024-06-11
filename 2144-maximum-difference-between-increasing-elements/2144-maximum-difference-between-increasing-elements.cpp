class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = -1;
        for(int i=0; i<nums.size(); i++) {
            int curr = -1;
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[j] > nums[i]) {
                    curr = nums[j] - nums[i];
                }
                res = max(res, curr);
            }
        }
        return res;
    }
};