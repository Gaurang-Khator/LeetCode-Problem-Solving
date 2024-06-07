class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose
        for(int i=0; i<matrix.size(); i++) {
            for(int j=i+1; j<matrix.size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //reverse rows
        for(int i=0; i<matrix.size(); i++) {
            int x = 0, y = matrix[0].size()-1;
            while(x < y) {
                swap(matrix[i][x], matrix[i][y]);
                x++;
                y--;
            }
        }
    }
};