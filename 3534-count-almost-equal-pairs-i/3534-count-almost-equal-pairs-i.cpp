class Solution {
public:
    bool helper(int x, int y) {
        string a1 = to_string(x);
        string a2 = to_string(y);

        if(a1.length() < a2.length()) {
            a1 = string(a2.length()-a1.length(), '0')+a1;
        } else if(a1.length() > a2.length()) {
            a2 = string(a1.length()-a2.length(), '0')+a2;
        }
        vector<int> temp;
        for(int i=0; i<a1.length(); i++) {
            if(a1[i] != a2[i]) {
                temp.push_back(i);
            }
        }
        if(temp.size()==0){
            return true;
        }
        if(temp.size()==2){
            swap(a1[temp[0]], a1[temp[1]]);
            return a1==a2;
        }
        return false;
    }
    int countPairs(vector<int>& nums) {
        int c=0;
        for(int i=0; i<nums.size(); i++) {
            for(int j = i+1; j<nums.size(); j++) {
                if(helper(nums[i],nums[j])) {
                    c++;
                }
            }
        }
        return c;
    }
    
};