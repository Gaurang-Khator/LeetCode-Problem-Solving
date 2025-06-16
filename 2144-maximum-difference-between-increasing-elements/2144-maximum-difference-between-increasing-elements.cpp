class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = -1;
        int minn = nums[0];
        for(int i: nums) {
            if(i > minn) {
                int diff = i - minn;
                maxDiff = max(maxDiff, diff);
            } else {
                minn = min(minn, i);
            }
        }
        return maxDiff;
    }
};