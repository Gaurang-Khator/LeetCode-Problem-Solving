class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minTime = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()){
            int s = q.size();
            bool temp = false;
            for(int i=0; i<s; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                for(auto d: dir) {
                    int nrow = r + d.first;
                    int ncol = c + d.second;
                    if(nrow < grid.size() && nrow>=0 && ncol>=0 && ncol < grid[0].size() && grid[nrow][ncol] == 1) {
                        q.push({nrow, ncol});
                        grid[nrow][ncol] = 2;
                        temp = true;
                    }
                }
            }
            if(temp) minTime++;
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return minTime;
    }
};