class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        unordered_map<string, int> mp;
        int n = s.length()/k;

        for(int i=0; i<s.length(); i+=n) {
            string sub = s.substr(i, n);
            mp[sub]++;
            string sub2 = t.substr(i, n);
            mp[sub2]--;
        }
        for(auto it: mp) {
            if(it.second != 0) return false;
        }        
        return true;
    }
};