class FindSumPairs {
    vector<int> n1, n2;
    unordered_map<int, int> mp;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for(int i: nums2) {
            mp[i]++;
        }
    }
    
    void add(int index, int val) {
        mp[n2[index]]--;
        n2[index] += val;
        mp[n2[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(int i: n1) {
            int req = tot - i;
            if(mp.find(req) != mp.end()) cnt += mp[req];
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */