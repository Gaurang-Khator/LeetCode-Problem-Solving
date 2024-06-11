class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt = 0;
        unordered_map<int, int> mp;
        for(auto x: nums) {
            cnt += mp[x];
            mp[x]++;
        }
        return cnt;
    }
};