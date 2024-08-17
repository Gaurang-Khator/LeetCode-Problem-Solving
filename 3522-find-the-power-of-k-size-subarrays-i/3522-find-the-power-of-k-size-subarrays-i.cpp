class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == k) {
            if(is_sorted(nums.begin(), nums.end())) {
                return {*max_element(nums.begin(), nums.end())};
            } else {
                return {-1};
            }
        }
        if(k == 1) {
            return nums;
        }
        vector<int> res;
        for(int i=0; i<=n-k; i++) {
            int m = INT_MIN;
            for(int j=i+1; j<(i+k); j++) {
                bool f = true;
                if(nums[j] == nums[j-1]+1) {
                    f = true;
                } else {
                    f = false;
                    m = -1;
                    break;
                }
                if(f) {
                    m = max(m, nums[j]);
                }
            }
            res.push_back(m);
        }
        return res;
    }
};