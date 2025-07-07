class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        unordered_map<int, vector<int>> mp;
        int minDay = INT_MAX, maxDay = 0;
        for(auto i: events) {
            int start = i[0];
            int end = i[1];
            mp[start].push_back(end);
            minDay = min(minDay, start);
            maxDay = max(maxDay, end);
        }
        int cnt = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=minDay; i<=maxDay; i++) {
            while(pq.empty()==false && pq.top() < i) {
                pq.pop();
            }
            for(auto j: mp[i]) {
                pq.push(j);
            }
            if(pq.empty()==false) {
                pq.pop();
                cnt++;
            }
        }
        return cnt;
    }
};