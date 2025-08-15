class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        while(n-- > 1) {
            string curr = "";
            for(int i=0; i<ans.length(); i++) {
                int cnt = 1;
                while(i+1<ans.length() && ans[i] == ans[i+1]){
                    cnt++;
                    i++;
                }
                curr = curr + (to_string(cnt) + ans[i]);
            }
            ans = curr;
        }
        return ans;
    }
};