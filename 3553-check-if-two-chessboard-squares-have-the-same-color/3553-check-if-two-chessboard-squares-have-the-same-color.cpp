class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        char c1 = coordinate1[0];
        char r1 = coordinate1[1];
        char c2 = coordinate2[0];
        char r2 = coordinate2[1];
        int col1 = (c1-'a' + r1-'1')%2;
        int col2 = (c2-'a' + r2-'1')%2;
        return col1==col2; 
    }
};