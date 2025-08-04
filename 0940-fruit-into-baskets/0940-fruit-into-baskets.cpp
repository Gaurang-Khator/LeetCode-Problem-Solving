class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        unordered_map<int, int> mp;
        int i = 0, j = 0, cnt = 0;
        while(j < fruits.size()){
            mp[fruits[j]]++;
            cnt++;
            while(mp.size() > 2) {
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
                cnt--;
            }
            ans = max(cnt, ans);
            j++;
        }
        return ans;
    }
};