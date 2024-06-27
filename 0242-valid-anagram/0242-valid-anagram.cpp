class Solution {
public:
    const 
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        if(s.length() != t.length()) {
            return false;
        }
        for(auto x: s) {
            mp[x]++;
        }
        for(auto x: t) {
            mp[x]--;
        }
        for(auto x: mp) {
            if(x.second != 0) {
                return false;
            }
        }
        return true;
    }
};