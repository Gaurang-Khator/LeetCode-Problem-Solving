class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> mp;
        for(int i=0; i<x.size(); i++) {
            mp[x[i]] = max(y[i], mp[x[i]]);
        }
        if(mp.size() < 3) return -1;

        priority_queue<int> pq;
        for(auto i: mp) {
            pq.push(i.second);
        }
        int sum = 0;
        for(int i=0; i<3; i++) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};