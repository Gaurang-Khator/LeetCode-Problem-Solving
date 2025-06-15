class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for(int i: nums) {
            res ^= i;
        }
        return res;
    }
};