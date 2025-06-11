class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        //BRUTE FORCE
        // for(int i=0; i<intervals.size(); i++) {
        //     int start = intervals[i][0];
        //     int end = intervals[i][1];
        //     if(res.empty() != true && end <= res.back()[1]) {
        //         continue;
        //     }
        //     for(int j=i+1; j<intervals.size(); j++) {
        //         if(end >= intervals[j][0]) {
        //             end = max(end, intervals[j][1]);
        //         } else {
        //             break;
        //         }
        //     }
        //     res.push_back({start, end});
        // }

        //OPTIMAL

        for(int i=0; i<intervals.size(); i++) {
            if(res.empty() ==true || intervals[i][0] > res.back()[1]) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};