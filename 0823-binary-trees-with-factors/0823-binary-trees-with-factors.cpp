class Solution {
public:
    const int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> mp;

        for(int i=0; i<n; i++) {
            mp[arr[i]] = 1;
            for(int j=0; j<n; j++) {
                if(i == j) continue;
                if(arr[i] % arr[j] == 0) {
                    mp[arr[i]] = (mp[arr[i]] + (mp[arr[j]] * mp[(arr[i]/arr[j])])%mod)%mod;
                }
            }
            ans = (ans + (mp[arr[i]]%mod))%mod;
        }
        return ans;
    }
};