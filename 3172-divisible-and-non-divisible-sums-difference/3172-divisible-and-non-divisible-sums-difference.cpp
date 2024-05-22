class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = (n*(n+1))/2;
        int num2 = (n*(n+1))/2;
        for(int i=1; i<=n; i++) {
            if(i>=m && i%m == 0) {
                num1 -= i;
            }
        }
        for(int i=1; i<=n; i++) {
            if(i%m != 0) {
                num2 -= i;
            }
        }
        return num1-num2;
    }
};