class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        for(int i=1; i<height.size()-1; i++) {
            int lmax = height[i], rmax = height[i];
            for(int j=0; j<i; j++) {
                lmax = max(lmax, height[j]);
            }
            for(int j=i+1; j<height.size(); j++) {
                rmax = max(rmax, height[j]);
            }
            res += (min(lmax, rmax) - height[i]);
        }
        return res;
    }
};