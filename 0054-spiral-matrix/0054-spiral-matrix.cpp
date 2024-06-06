class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int topRow = 0, bottomRow = matrix.size()-1;
        int leftCol = 0, rightCol = matrix[0].size()-1;
        while(topRow <= bottomRow && leftCol <= rightCol) {
            for(int i=leftCol; i<=rightCol; i++) { //top row
                res.push_back(matrix[topRow][i]);
            }
            topRow++;
            for(int i=topRow; i<=bottomRow; i++) { //right col
                res.push_back(matrix[i][rightCol]);
            }
            rightCol--;
            if(topRow <= bottomRow) {
                for(int i=rightCol; i>=leftCol; i--) { //bottom row
                    res.push_back(matrix[bottomRow][i]);
                }
                bottomRow--;
            }
            if(leftCol <= rightCol) {
                for(int i=bottomRow; i>=topRow; i--) { //left col
                    res.push_back(matrix[i][leftCol]);
                }
                leftCol++;
            }
        }
        return res;
    }
};