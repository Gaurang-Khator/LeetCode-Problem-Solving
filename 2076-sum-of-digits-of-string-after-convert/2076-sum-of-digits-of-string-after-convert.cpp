class Solution {
public:
    int getLucky(string s, int k) {
        string temp = "";
        for(auto x: s) {
            temp += to_string(x-'a'+1);
        }
        while(k--) {
            int x = 0;
            for(char c: temp) {
                x += c-'0';
            }
            temp = to_string(x);
        }
        return stoi(temp);
    }
};