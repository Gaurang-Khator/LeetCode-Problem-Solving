class Solution {
public:
    string reverseWords(string s) {
        // stringstream ss(s);
        // vector<string> words;
        // string temp;
        // while(ss >> temp) {
        //     words.push_back(temp);
        // }
        // string rev = "";
        // for(int i=words.size()-1; i>=0; i--) {
        //     if(i==0) {
        //         rev += words[i];
        //         break;
        //     }
        //     rev += words[i] + " ";
        // }
        // return rev;

        string rev = "";
        string temp ="";
        for(int i=0; i<s.length(); i++) {
            while(i<s.length() && s[i] != ' ') {
                temp += s[i];
                i++;
            } if(s[i] == ' ' && s[i+1] != ' ') {
                rev = temp + " " + rev;
                temp = "";
            }
        }
        rev = temp + " " + rev;
        int i = 0, j = rev.length()-1;
        while(rev[i] == ' ') i++;
        while(rev[j] == ' ') j--;
        rev = rev.substr(i, j-i+1);
        return rev;
    }
};