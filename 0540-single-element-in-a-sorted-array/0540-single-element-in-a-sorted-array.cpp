class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // int res = 0;
        // for(int i: nums) {
        //     res ^= i;
        // }
        // return res;

        int i = 0, j = nums.size()-1;
        while(i < j) {
            int mid = i + (j-i)/2;
            if((mid%2 == 0 && nums[mid] == nums[mid+1]) || (mid%2 == 1 && nums[mid] == nums[mid-1])) {
                i = mid+1;
            } else {
                j = mid;
            }
        }
        return nums[i];
    }
};