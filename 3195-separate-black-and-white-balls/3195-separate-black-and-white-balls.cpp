class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        int i = 0, j = s.length()-1;
        while(i < j) {
            while(i<s.length() && s[i] == '0' ) {
                i++;
            } while(j>=0 && s[j] == '1' ) {
                j--;
            }
            if(s[i] == '1' && i<j) {
                swap(s[i], s[j]);
                res += j-i;
                i++;
                j--;
            }
        }
        return res;      
    }
};