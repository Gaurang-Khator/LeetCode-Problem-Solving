class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string temp = "";
        for(int i=0; i<s.length(); i++) {
            if(s[i] == ' ' && s[i+1] != ' ') {
                res = temp + " " + res;
                temp = "";
            } else if(s[i] != ' ') {
                temp += s[i];
            } else {
                continue;
            }
        }
        res = temp + " " + res;
        int i = 0, j = res.length()-1;
        while(res[i] == ' ') i++;
        while(res[j] == ' ') j--;
        return res.substr(i, j-i+1);
    }
};