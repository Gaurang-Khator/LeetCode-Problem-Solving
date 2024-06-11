class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // int res = -1;
        // for(int i=0; i<nums.size(); i++) {
        //     int curr = -1;
        //     for(int j=i+1; j<nums.size(); j++) {
        //         if(nums[j] > nums[i]) {
        //             curr = nums[j] - nums[i];
        //         }
        //         res = max(res, curr);
        //     }
        // }
        // return res;

        int res = -1, minEle = nums[0];
        for(int i=1; i<nums.size(); i++) {
            int curr = nums[i] - minEle;
            res = max(res, curr);
            minEle = min(minEle, nums[i]);
        }
        if(res == 0) {
            return -1;
        }
        return res;
    }
};