class Solution {
public:
    int helper(int right, int left, int start) {
        int rTol = abs(right-start) + (right-left);
        int lTor = abs(start-left) + (right-left);
        return min(rTol, lTor);
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int ans = 0;
        int left = 0, sum = 0;
        for(int right = 0; right<fruits.size(); right++) {
            sum += fruits[right][1];
            while(left <= right && helper(fruits[right][0], fruits[left][0], startPos) > k) {
                sum -= fruits[left][1];
                left++;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};