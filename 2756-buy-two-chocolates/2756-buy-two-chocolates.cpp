class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int s = prices[0] + prices[1];
        if(s > money) return money;
        return (money - s);
    }
};