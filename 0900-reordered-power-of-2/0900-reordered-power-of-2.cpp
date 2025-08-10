class Solution {
public:
    bool solve(int n) {
        return ((n & (n-1)) == 0);
    }
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        bool res = false;
        do{
            if(s[0]=='0') continue;
            if(solve(stoi(s))){
                res = true;
                break;
            }

        }while(next_permutation(s.begin(), s.end()));
        return res;
    }
};