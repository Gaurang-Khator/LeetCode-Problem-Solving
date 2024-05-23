class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // set<vector<int>> s;
        vector<vector<int>> ans;

        if(nums.size() < 3) {
            return ans;
        }
        
        for(int i=0; i<nums.size(); i++) {
            if(i>0 && nums[i] == nums[i-1]) {
                continue;
            }
            int j = i+1;
            int k = nums.size()-1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    // s.insert({nums[i], nums[j], nums[k]});
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j]==nums[j-1]) {
                        j++;
                    } 
                    while(j < k && nums[k] == nums[k+1]) {
                        k--;
                    }
                } else if(sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
            
        }
        // for(auto triplets: s) {
        //     ans.push_back(triplets);
        // }
        return ans;
    }
};