class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0, maj1 = INT_MIN, maj2 = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            if(count1 == 0 && nums[i] != maj2) {
                maj1 = nums[i];
                count1++;
            }
            else if(count2 == 0 && nums[i] != maj1) {
                maj2 = nums[i];
                count2++;
            } else if(nums[i] == maj1) {
                count1++;
            } else if(nums[i] == maj2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1 = 0, count2 = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == maj1) {
                count1++;
            }
            if(nums[i] == maj2) {
                count2++;
            }
        }
        if(count1 > nums.size()/3) {
            ans.push_back(maj1);
        }
        if(count2 > nums.size()/3) {
            ans.push_back(maj2);
        }
        return ans;
    }
};