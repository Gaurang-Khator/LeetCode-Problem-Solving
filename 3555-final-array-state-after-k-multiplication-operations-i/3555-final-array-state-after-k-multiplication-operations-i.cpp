class Solution {
public:
    int helper(vector<int> nums) {
        int x = INT_MAX;
        for(auto i: nums) {
            if(i < x) {
                x = i;
            }
        }
       
        return x;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i=0; i<k; i++) {
            int m = helper(nums);
            for(int j=0; j<nums.size(); j++) {
                if(nums[j] == m) {
                    nums[j] *= multiplier;
                    break;
                }
            }
           
        }
        return nums;
    }
};