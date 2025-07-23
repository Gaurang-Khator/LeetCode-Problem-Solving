class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0;
        int i = 0, j = 0;
        int maxScore = 0;
        while(j < nums.size()){
            sum += nums[j];
            mp[nums[j]]++;
            while(j-i+1 > mp.size()) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
            if(j-i+1 == mp.size()) {
                maxScore = max(maxScore, sum);
            }
            j++;
        }
        return maxScore;
    }
};