class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
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