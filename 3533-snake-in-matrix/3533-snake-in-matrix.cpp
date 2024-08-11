class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0;
        int j = 0;
        int ans = 0;
        for(int x=0; x<commands.size(); x++) {
            if(commands[x] == "UP") {
                i--;
            } else if(commands[x] == "RIGHT") {
                j++;
            } else if(commands[x] == "DOWN") {
                i++;
            } else {
                j--;
            }
        }
        ans = (i*n)+j;
        return ans;
    }
};