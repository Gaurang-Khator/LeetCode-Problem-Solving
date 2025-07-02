class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int i = 0, j = 0;
        int cnt = 0;
        long long prod = 1;
        while(j < nums.size()) {
            prod *= nums[j];
            while(i<nums.size() && prod >= k) {
                prod /= nums[i];
                i++;
            }
            if(prod < k) {
                cnt += j-i+1;
            } 
            j++;
        }
        return cnt;
    }
};