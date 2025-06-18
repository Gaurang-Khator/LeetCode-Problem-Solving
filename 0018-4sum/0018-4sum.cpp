class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        // set<vector<int>> s;
        // for(int a=0; a<n; a++) {
        //     for(int b=a+1; b<n; b++) {
        //         for(int c=b+1; c<n; c++) {
        //             for(int d=c+1; d<n; d++) {
        //                 long long sum = (long long)nums[a]+ (long long)nums[b]+ (long long)nums[c]+ (long long)nums[d];
        //                 if(sum == target) {
        //                     vector<int> temp ={nums[a], nums[b], nums[c], nums[d]};
        //                     sort(temp.begin(), temp.end());
        //                     s.insert(temp);
        //                 }
        //             }
        //         }
        //     }
        // }

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int a=0; a<n; a++) {
            if(a>0 && nums[a] == nums[a-1]) continue;
            for(int b=a+1; b<n; b++) {
                if(b > a+1 && nums[b] == nums[b-1]) continue;
                int c = b+1, d = n-1;
                while(c < d) {
                    long long sum = nums[a]+nums[b];
                    sum += nums[c];
                    sum += nums[d];
                    if(sum == target) {
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});
                        c++, d--;
                        while(c<d && nums[c] == nums[c-1]) c++;
                        while(c<d && nums[d] == nums[d+1]) d--;
                    } else if(sum > target) {
                        d--;
                    } else {
                        c++;
                    }
                }
            }
        }
        return res;
    }
};