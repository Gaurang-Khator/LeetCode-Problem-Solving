class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 0;
        for(int i=0; i<nums.size(); i++) {
            if(res < 2 || nums[i] > nums[res-2]) {
                nums[res] = nums[i];
                res++;
            }
        }
        return res;
    }
};