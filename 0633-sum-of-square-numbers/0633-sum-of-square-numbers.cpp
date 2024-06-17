class Solution {
public:
    bool judgeSquareSum(int c) {
        long long s = 0, e = sqrt(c);
        while(s <= e) {
            long long curr = (s*s) + (e*e);
            if(curr < c) {
                s++;
            } else if(curr > c) {
                e--;
            } else {
                return true;
            }
        }
        return false;
    }
};