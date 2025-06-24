class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> s;
        for(int i=0; i<nums.size(); i++) {
            int j = 1;
            if(nums[i] == key) {
                s.insert(i);
                while(j <= k) {
                    if(i-j >= 0) s.insert(i-j);
                    if(i+j < nums.size()) s.insert(i+j);
                    j++;
                }
            }
        }
        vector<int> res(s.begin(), s.end());
        return res;
    }
};