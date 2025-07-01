class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        for(int i=0; i<k; i++) {
            lsum += cardPoints[i];
        }
        int maxSum = lsum;
        int j = cardPoints.size()-1;
        // int rsum = 0;
        for(int i=k-1; i>=0; i--) {
            lsum -= cardPoints[i];
            // rsum += cardPoints[j--];
            lsum += cardPoints[j--];
            maxSum = max(maxSum, lsum);
        }
        return maxSum;
    }
};