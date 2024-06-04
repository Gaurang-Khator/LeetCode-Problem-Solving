class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int len = 0;
        for(auto ch: s) {
            mp[ch]++;
            if(mp[ch] % 2 == 0) {
                len += 2;
            }
        }
        for(auto x: mp) {
            if(x.second % 2 == 1) {
                len++;
                break;
            }
        }
        return len;
    }
};