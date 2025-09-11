class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;
        for(int i=0; i<n; i++) {
            int cnt = 1;
            int temp = i+1;
            while(temp < n && chars[temp] == chars[i]) {
                cnt++;
                temp++;
            }
            i = temp-1;
            if(cnt > 1) {
                chars[idx++] = chars[i];
                for(auto x: to_string(cnt)) chars[idx++] = x;
            }
            else chars[idx++] = chars[i];
        }
        return idx;
    }
};