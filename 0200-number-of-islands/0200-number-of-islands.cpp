class Solution {
public:
    void bfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> &grid) {
        vis[r][c] = 1;
        queue<pair<int, int>> q;
        q.push({r, c});
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto d: dir) {
                int nr = row + d.first;
                int nc = col + d.second;
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == '1' && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    bfs(i, j, vis, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};