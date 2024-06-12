class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //BRUTE FORCE

        // int res = INT_MIN;
        // for(int i=0; i<nums.size(); i++) {
        //     int curr = 0;
        //     for(int j=i; j<nums.size(); j++) {
        //         curr += nums[j];
        //         res = max(res, curr);
        //     }
        // }
        // return res;

        //KADANE'S ALGO

        // int res = INT_MIN, sum = 0;
        // for(int i=0; i<nums.size(); i++) {
        //     sum += nums[i];
        //     res = max(res, sum);
        //     if(sum < 0) {
        //         sum = 0;
        //     }
        // }
        // return res;

        int res = INT_MIN, curr = 0;
        for(int i=0; i<nums.size(); i++) {
            curr += nums[i];
            curr = max(curr, nums[i]);
            res = max(curr, res);
        }
        return res;
    }
};