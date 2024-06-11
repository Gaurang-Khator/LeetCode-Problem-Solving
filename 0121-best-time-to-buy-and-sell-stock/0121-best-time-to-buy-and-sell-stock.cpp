class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0, mn = prices[0];
        for(int i=1; i<prices.size(); i++) {
            int currProf = prices[i] - mn;
            maxProf = max(maxProf, currProf);
            mn = min(mn, prices[i]);
        }
        return maxProf;
    }
};