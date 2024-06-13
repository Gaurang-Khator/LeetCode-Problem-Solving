class Solution {
public:
    int trap(vector<int>& height) {

        // int res = 0;
        // for(int i=1; i<height.size()-1; i++) {
        //     int lmax = 0, rmax = 0;
        //     for(int j=0; j<=i; j++) {
        //         lmax = max(lmax, height[j]);
        //     }
        //     for(int j=i; j<height.size(); j++) {
        //         rmax = max(rmax, height[j]);
        //     }
        //     res += (min(lmax, rmax) - height[i]);
        // }
        // return res;

        //OPTIMIZED

        int res = 0;
        int lmax[height.size()], rmax[height.size()];
        lmax[0] = height[0];
        rmax[height.size()-1] = height[height.size()-1];
        for(int i=1; i<height.size(); i++) {
            lmax[i] = max(height[i], lmax[i-1]);
        }
        for(int i=height.size()-2; i>=0; i--) {
            rmax[i] = max(height[i], rmax[i+1]);
        }
        for(int i=1; i<height.size()-1; i++) {
            res += (min(lmax[i], rmax[i]) - height[i]);
        }
        return res;
    }
};