class Solution {
public:
    int minSwaps(string s) {
        int minswap = 0, balance = 0;
        int j = s.length()-1;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '[') {
                balance++;
            } else {
                balance--;
            }
            if(balance < 0) {
                while(i<j && s[j] != '[') {
                    j--;
                }
                swap(s[i], s[j]);
                minswap++;
                balance = 1;
            }
        }
        return minswap;
    }
};