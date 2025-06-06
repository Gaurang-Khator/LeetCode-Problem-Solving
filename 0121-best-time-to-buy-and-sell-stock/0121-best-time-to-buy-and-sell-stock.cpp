class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, profit = 0;
        int minBuy = prices[0];
        for(int i=1; i<prices.size(); i++) {
            profit = prices[i] - minBuy;
            maxProfit = max(maxProfit, profit);

            minBuy = min(minBuy, prices[i]);
        }
        return maxProfit;
    }
};