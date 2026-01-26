class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        int mindiff = arr[1]-arr[0];
        res.push_back({arr[0], arr[1]});

        for(int i=1; i<arr.size()-1; i++) {
            int diff = arr[i+1] - arr[i];
            if(diff == mindiff) {
                res.push_back({arr[i], arr[i+1]});
            }
            if(diff < mindiff) {
                res.erase(res.begin(), res.end());
                mindiff = diff;
                res.push_back({arr[i], arr[i+1]});
            }
        }
        return res;
    }
};