class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f = 0, t = 0, tw = 0;
        for(int i: bills) {
            if(i==5) f++;
            else if(i==10) {
                if(f != 0) {
                    f--;
                    t++;
                } else return false;
            } else {
                if(t > 0 && f > 0) {
                    tw++;
                    t--;
                    f--;
                } else if(f >= 3) {
                    f -= 3;
                    tw++;
                } else return false;
            }
        }
        return true;
    }
};