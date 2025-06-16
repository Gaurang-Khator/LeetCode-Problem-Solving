class Solution {
public:
    string generateTag(string caption) {
        string res = "#";
        transform(caption.begin(), caption.end(), caption.begin(), ::tolower);
        int i=0;
        while(i<caption.length()) {
            if(caption[i] == ' ' ) {
                while(i < caption.length() && caption[i] == ' ') {
                    i++;
                }
                if(i < caption.length() && res.length()>1) {
                    res += (char)toupper(caption[i]);
                    i++;
                } 
            } else {
                res += caption[i];
                i++;
            }
        }
        while(res[res.length()-1] == ' ') {
            res.pop_back();
        }
        if(res.length() > 100) {
            res = res.substr(0, 100);
        }
        return res;
    }
};