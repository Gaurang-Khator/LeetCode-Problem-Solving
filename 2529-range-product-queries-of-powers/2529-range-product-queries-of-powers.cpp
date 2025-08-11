class Solution {
public:
    const int MOD = 1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        vector<int> power;
        vector<int> total;
        long long temp = n;
        for(int i=0; i<32; i++) {
            if(pow(2, i) <= temp) {
                total.push_back(pow(2, i));
            }
        }
        for(int i=total.size()-1; i>=0; i--) {
            if(temp >= total[i]){
                temp -= total[i];
                power.push_back(total[i]);
            }
        }
        reverse(power.begin(), power.end());
        // int x = power.size();
        // vector<long long> pref(x);
        // pref[0] = power[0];
        // for(int i=1; i<x; i++) {
        //     pref[i] = (pref[i-1] * power[i]);
        // }
        // for(int i=0; i<queries.size(); i++) {
        //     int start = queries[i][0];
        //     int end = queries[i][1];
        //     if(start == 0) res.push_back(pref[end]%MOD);
        //     else res.push_back((pref[end]/pref[start-1])%MOD);            
        // }
        // return res;
        for(int i=0; i<queries.size(); i++) {
            int st = queries[i][0];
            int end = queries[i][1];
            long long val = 1;
            for(int j=st; j<=end; j++) {
                val = (val%MOD * power[j]%MOD)  % MOD;
            }
            res.push_back(val);
        }
        return res;
    }
};