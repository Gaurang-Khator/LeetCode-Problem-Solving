class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        //FOR N*N
        //for(int i=0; i<matrix.size(); i++) {
        //     for(int j=i+1; j<matrix.size(); j++) {
        //         swap(matrix[i][j], matrix[j][i]);
        //     }
        // }
        // return matrix;
        
        // vector<vector<int>> temp(matrix[0].size(), vector<int>(matrix.size(), 0));
        // for(int i=0; i<matrix.size(); i++) {
        //     for(int j=0; j<matrix[0].size(); j++) {
        //         temp[j][i] = matrix[i][j];
        //     }
        // }
        // return temp;
        vector<vector<int>> res;
        for(int j=0; j<matrix[0].size(); j++) { //column
            vector<int> temp;
            for(int i=0; i<matrix.size(); i++) { //row
                temp.push_back(matrix[i][j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};