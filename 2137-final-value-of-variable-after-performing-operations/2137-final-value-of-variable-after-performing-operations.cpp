class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(int i = 0; i<operations.size(); i++) {
            string temp = operations[i];
            if(temp[1] == '+') {
                x += 1;
            } else {
                x -= 1;
            }
        }
        return x;
    }
};