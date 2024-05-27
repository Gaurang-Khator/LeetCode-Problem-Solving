class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1, j = num;
        while(i <= j) {
            int mid = i + (j-i)/2;;
            long long sq = (long long)mid*mid;
            if(sq == num) {
                return true;
            } else if(sq > num) {
                j = mid-1;
            } else {
                i = mid+1;
            }
        }
        return false;
    }
};