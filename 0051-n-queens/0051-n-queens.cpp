class Solution {
public:

    bool isSafe(int row, int col, vector<string> temp, int n) {
        //check left
        for(int i=col; i>=0; i--) {
            if(temp[row][i] == 'Q') return false;
        }

        //check left diagonal up
        int r = row, c = col;
        while(r>=0 && c>=0) {
            if(temp[r][c] == 'Q') return false;
            r--;
            c--;
        }

        //check left diagonal down
        while(row<n && col>=0) {
            if(temp[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }

    void placeQueens(vector<vector<string>> &res, vector<string> &temp, int n, int col) {
        if(col == n) {
            res.push_back(temp);
            return;
        }

        for(int row=0; row<n; row++) {
            if(isSafe(row, col, temp, n)){
                temp[row][col] = 'Q';
                placeQueens(res, temp, n, col+1);
                temp[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> temp(n, string(n, '.'));
        placeQueens(res, temp, n, 0);
        return res;
    }
};