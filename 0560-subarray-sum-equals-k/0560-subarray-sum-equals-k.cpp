class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefSum = 0;
        int cnt = 0;
        for(int i=0; i<nums.size(); i++) {
            prefSum += nums[i];
            if(mp.find(prefSum - k) != mp.end()) {
                cnt += mp[prefSum-k];
            }
            mp[prefSum]++;
        }
        return cnt;
    }
};