class Solution {
public:
    int dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        queue<pair<int, int>> q;
        q.push({r, c});
        vis[r][c] = 1;
        long long sum = grid[r][c];
        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            for(int i=0; i<4; i++) {
                int nr = node.first + dir[i][0];
                int nc = node.second + dir[i][1];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] > 0 && !vis[nr][nc]) {
                    sum += grid[nr][nc];
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] > 0) {
                    int s = dfs(i, j, grid, vis);
                    if(s%k == 0) cnt++;
                }
            }
        }
        return cnt;
    }
};