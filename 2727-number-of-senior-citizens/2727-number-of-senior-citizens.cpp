class Solution {
public:
    int countSeniors(vector<string>& details) {
        int c = 0;
        for(auto x: details) {
            if(x[11] > '6' || (x[11] == '6' && x[12] > '0')) {
                c++;
            }
        }
        return c;
    }
};