class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int i = grid.size();
        int j = grid[0].size();
        for(int x=0; x<i; x++) {
            for(int y=0; y<j; y++) {
                if((x+1<i && grid[x][y] != grid[x+1][y]) || (y+1<j && grid[x][y] == grid[x][y+1])) {
                    return false;
                }
            }
        }
        return true;
    }
};