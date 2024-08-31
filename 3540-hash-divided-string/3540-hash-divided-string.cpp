class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.length();
        string res = "";
        for(int i=0; i<n; i+=k) {
            int sum = 0;
            for(int j=i; j<i+k; j++) {
                sum += s[j] - 'a';
            }
            int hc = sum%26;
            char hashedChar = 'a' + hc;
            res += hashedChar;
        }
        return res;
    }
};