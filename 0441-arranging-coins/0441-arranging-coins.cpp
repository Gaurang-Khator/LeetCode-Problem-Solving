class Solution {
public:
    int arrangeCoins(int n) {
        int cnt = 0;
        int i = 1;
        while(n >= 0) {
            n -= i;
            i++;
            cnt++;
        }
        return cnt-1;
    }
};