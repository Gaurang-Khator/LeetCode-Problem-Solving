class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> count((n*n)+1, 0);
        int a = -1, b = -1;

        for(auto r: grid) {
            for(auto i: r) {
                count[i]++;
            }
        }
        for(int i=1; i<=n*n; i++) {
            if(count[i] == 2) a = i;
            if(count[i] == 0) b = i;
        }
        return {a, b};
    }
};