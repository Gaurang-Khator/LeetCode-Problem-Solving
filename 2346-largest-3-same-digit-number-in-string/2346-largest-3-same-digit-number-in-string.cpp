class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        while(j < num.length()){
            mp[num[j]]++;
            if(j-i+1 == 3) {
                if(mp.size() == 1) {
                    string temp = num.substr(i, 3);
                    if(ans == "" || temp > ans) ans = temp;
                }
                mp[num[i]]--;
                if(mp[num[i]] == 0) mp.erase(num[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};