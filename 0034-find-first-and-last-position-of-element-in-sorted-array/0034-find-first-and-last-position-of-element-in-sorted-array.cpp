class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while(i <= j) {
            int mid = i + (j-i)/2;
            if(nums[mid] == target) {
                int temp = mid-1;
                while(temp>=0 && nums[temp] == target) temp--;
                int temp2 = mid+1;
                while(temp2 < nums.size() && nums[temp2] == target) temp2++;
                return {temp+1, temp2-1};
            } else if(nums[mid] > target) {
                j = mid-1;
            } else {
                i = mid+1;
            }
        }
        return {-1, -1};
    }
};