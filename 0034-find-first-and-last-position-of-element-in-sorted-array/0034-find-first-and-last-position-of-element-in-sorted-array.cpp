class Solution {
public:
    int firstPos(vector<int> &nums, int n, int target) {
        int i = 0, j = n-1;
        while(i <= j) {
            int mid = i + (j-i)/2;
            if(nums[mid] > target) {
                j = mid-1;
            } else if(nums[mid] < target) {
                i = mid+1;
            } else {
                if(mid == 0 || nums[mid-1] != nums[mid]) {
                    return mid;
                } else {
                    j = mid-1;
                }
            }
        }
        return -1;
    }
    int lastPos(vector<int> &nums, int n, int target) {
        int i = 0, j = n-1;
        while(i <= j) {
            int mid = i + (j-i)/2;
            if(nums[mid] > target) {
                j = mid-1;
            } else if(nums[mid] < target) {
                i = mid+1;
            } else {
                if(mid == n-1 || nums[mid+1] != nums[mid]) {
                    return mid;
                } else {
                    i = mid+1;
                }
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(firstPos(nums, n, target));
        ans.push_back(lastPos(nums, n, target));
        return ans;
    }
};