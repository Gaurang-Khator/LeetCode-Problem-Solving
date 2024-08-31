class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        string s3 = to_string(num3);
        if(s1.length() < 4) {
            s1.insert(0, 4-s1.length(), '0');
        }
        if(s2.length() < 4) {
            s2.insert(0, 4-s2.length(), '0');
        }
        if(s3.length() < 4) {
            s3.insert(0, 4-s3.length(), '0');
        }
        string key = "";
        for(int i=0; i<4; i++) {
            int digit1 = s1[i] - '0';
            int digit2 = s2[i] - '0';
            int digit3 = s3[i] - '0';
            key += to_string(min(min(digit1, digit2), digit3));
        }
        return stoi(key);
    }
};