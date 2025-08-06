class Solution {
public:
    int seg[4 * 100000];
    void build(int idx, int l, int h, vector<int>& baskets) {
        if(l == h) {
            seg[idx] = baskets[l];
            return;
        }
        int mid = (l+h)/2;
        build(2*idx+1, l, mid, baskets);
        build(2*idx+2, mid+1, h, baskets);
        seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
    }
    bool query(int val, int idx, int l, int h) {
        if(val > seg[idx] && seg[idx] != -1) return false;
        
        if(l == h) {
            seg[idx] = -1;
            return true;
        }

        int mid = (l+h)/2;
        if(val <= seg[2*idx+1]) bool left = query(val, 2*idx+1, l, mid);
        else bool right = query(val, 2*idx+2, mid+1, h);
        seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
        return left || right;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        build(0, 0, n-1, baskets);
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(!query(fruits[i], 0, 0, n-1)) cnt++;
        }
        return cnt;
    }
};