class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        // int i = 0, j = 0;
        // int maxFreq = 0;
        // unordered_map<char, int> mp;
        // unordered_map<string, int> sub;
        // while(j < s.length()) {
        //     mp[s[j]]++;
        //     if(j-i+1 < minSize) {
        //         j++;
        //     } 
        //     else if((j-i+1 >= minSize) && mp.size() <= maxLetters) {
        //         string temp = s.substr(i, j-i+1);
        //         sub[temp]++;
        //         j++;
        //     } else if(mp.size() > maxLetters){
        //         mp[s[i]]--;
        //         if(mp[s[i]] == 0) mp.erase(s[i]);
        //         i++;
        //         j++;
        //     }
        // }
        // for(auto s: sub) {
        //     maxFreq = max(maxFreq, s.second);
        // }
        // return maxFreq;

        unordered_map<char, int> um1;
        for (int i = 0; i < minSize; i++) {
            um1[s[i]]++;
        }
        um1[s[minSize-1]]--;

        unordered_map<string, int> um2;
        for (int i = 0; i <= s.size()-minSize; i++) {
            um1[s[i+minSize-1]]++;
            if (um1.size() <= maxLetters) {
                um2[s.substr(i, minSize)]++;
            }
            if (--um1[s[i]] == 0) um1.erase(s[i]);
        }

        int mx = 0;
        for (auto &x : um2) {
            mx = max(mx, x.second);
        }

        return mx;
    }
};