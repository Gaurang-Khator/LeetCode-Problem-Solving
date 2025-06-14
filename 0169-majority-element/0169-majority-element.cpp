class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int, int> mp;
        // for(int i: nums) {
        //     mp[i]++;
        // }
        // for(auto i: mp) {
        //     if(i.second > nums.size()/2) {
        //         return i.first;
        //     }
        // }
        // return -1;
        int cnt = 0;
        int ele;
        for(int i: nums) {
            if(cnt == 0) {
                ele = i;
                cnt++;
            }
            else if(i == ele) cnt++;
            else cnt--;
        }
        return ele;
    }
};