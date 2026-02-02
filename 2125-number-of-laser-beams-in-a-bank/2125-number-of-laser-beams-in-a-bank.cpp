class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cnt = 0, rows = bank.size();
        map<int, int> mp;
        for(int i=0; i<rows; i++) {
            string r = bank[i];
            int cntone = 0;
            for(auto i: r) {
                if(i == '1') cntone++;
            }
            if(cntone > 0) mp[i+1] = cntone;
        }
        if(mp.size() <= 1 ) return 0;
        
        vector<int> temp(mp.size());
        for(auto it: mp) temp.push_back(it.second);

        for(int i=0; i<temp.size()-1; i++) {
            cnt += (temp[i]*temp[i+1]);
        }
        return cnt;
    }
};