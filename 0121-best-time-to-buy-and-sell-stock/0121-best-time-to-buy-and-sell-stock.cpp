class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int minBuy = INT_MAX;
        for(int i: prices) {
            minBuy = min(minBuy, i);
            maxProf = max(maxProf, i-minBuy);
        }
        return maxProf;
    }
};