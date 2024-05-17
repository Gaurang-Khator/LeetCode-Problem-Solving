class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //BRUTE FORCE - O(n)
        // int a = 0;
        // for(int i=0; i<nums.size(); i++) {
        //     a = a^nums[i];
        // }
        // return a;

        //OPTIMIZED - O(log n)
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        if(nums[0] != nums[1]) {
            return nums[0];
        }
        if(nums[n-1] != nums[n-2]) {
            return nums[n-1];
        }
        int i = 1, j = n-2;
        while(i <= j) {
            int m = (i+j)/2;
            if(nums[m] != nums[m+1] && nums[m] != nums[m-1]) {
                return nums[m];
            }
            if((m%2==0 && nums[m] == nums[m+1]) || (m%2==1 && nums[m] == nums[m-1])) {
                i = m+1;
            } else {
                j = m-1;
            }
        }
        return -1;
    }
};