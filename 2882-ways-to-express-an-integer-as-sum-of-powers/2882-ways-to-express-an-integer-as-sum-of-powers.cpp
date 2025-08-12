class Solution {
public:
    const int mod = 1e9+7;
    int solve(vector<int>&arr, int n, int idx, vector<vector<long long>> &memo) {
        if(idx == arr.size()) {
            if(n == 0) return 1;
            else return 0;
        }
        if(memo[n][idx] != -1) return memo[n][idx];
        int exc = solve(arr, n, idx+1, memo);
        int inc = 0;
        if(n >= arr[idx]) inc = solve(arr, n-arr[idx], idx+1, memo);
        memo[n][idx] = (exc+inc)%mod;
        return memo[n][idx];
    }
    int numberOfWays(int n, int x) {
        vector<int> arr;
        for(int i=1; i<=n; i++) {
            if(pow(i, x) <= n) arr.push_back(pow(i, x));
            else break;
        }
        // int cnt = 0;
        reverse(arr.begin(), arr.end());
        vector<vector<long long>> memo(n+1, vector<long long>(arr.size()+1, -1));
        return solve(arr, n, 0, memo);
        // return cnt;
    }
};