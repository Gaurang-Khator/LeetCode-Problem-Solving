class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> res;
        stack<int> s;
        s.push(height[0]);
        for(int i=1; i<height.size(); i++) {
            if(s.top() > threshold) {
                res.push_back(i);
            }
            s.push(height[i]);
        }
        return res;
    }
};