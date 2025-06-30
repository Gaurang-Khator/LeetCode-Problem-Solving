class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        // for(int i=0; i<matrix.size(); i++) {
        //     for(int j=i+1; j<matrix[0].size(); j++) {
        //         swap(matrix[i][j], matrix[j][i]);
        //     }
        // }
        // return matrix;
        vector<vector<int>> res(matrix[0].size(), vector<int>(matrix.size()));
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
};