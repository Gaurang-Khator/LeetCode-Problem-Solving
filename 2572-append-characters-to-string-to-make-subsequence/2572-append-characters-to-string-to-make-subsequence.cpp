class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        int l1 = s.length(), l2 = t.length();
        while(i < l1 && j < l2) {
            if(s[i] == t[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return l2-j;
    }
};