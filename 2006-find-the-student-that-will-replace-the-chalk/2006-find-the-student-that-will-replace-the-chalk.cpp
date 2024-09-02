class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long s = 0;
        for(int x:chalk) {
            s += x;
        }
        int r = k%s;
        if(r == 0) {
            return 0;
        }
        for(int i=0; i<chalk.size(); i++) {
            if(r >= chalk[i]) {
                r -= chalk[i];
            } else {
                return i;
            }
            
        }
        return 0;
    }
};