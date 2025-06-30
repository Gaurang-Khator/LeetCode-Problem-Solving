class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res(nums.size());
        // for(int i: nums) {
        //     if(i < pivot) res.push_back(i);
        // }
        // for(int i: nums) {
        //     if(i == pivot) res.push_back(i);
        // }
        // for(int i: nums) {
        //     if(i > pivot) res.push_back(i);
        // }
        // return res;
        int l = 0, r = nums.size()-1;
        int j = nums.size()-1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < pivot) {
                res[l] = nums[i];
                l++;
            }if(nums[j] > pivot) {
                res[r] = nums[j];
                r--;
            }
            j--;
        }
        while(l <= r) {
            res[l] = pivot;
            l++;
        }
        return res;
    }
};