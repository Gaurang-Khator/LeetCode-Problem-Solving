class Solution {
public:
    int strStr(string haystack, string needle) {
        // for(int i=0; i<haystack.length(); i++) {
        //     if(haystack[i] == needle[0]) {
        //         int temp = i+1;
        //         bool f = true;
        //         for(int j=1; j<needle.size(); j++) {
        //             if(haystack[temp] != needle[j]) {
        //                 f = false;
        //                 break;
        //             }
        //             temp++;
        //         }
        //         if(f) return i;
        //     }
        // }
        // return -1;
        int i = 0, j = 0;
        string s = "";
        while(j < haystack.size()) {
            s += haystack[j];
            if(j-i+1 == needle.length()) {
                if(needle == s) return i;
                s.erase(s.begin());
                i++;
            }
            j++;
        }
        return -1;
    }
};