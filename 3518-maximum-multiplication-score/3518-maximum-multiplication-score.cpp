class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        long long max_i0 = LLONG_MIN;
        long long max_i1 = LLONG_MIN;
        long long max_i2 = LLONG_MIN;
        long long max_i3 = LLONG_MIN;
        int n = b.size();

        for (int i = 0; i < n; i++) {
            if (i >= 3) {
                max_i3 = max(max_i3, max_i2 + static_cast<long long>(a[3]) * b[i]);
            }
            if (i >= 2) {
                max_i2 = max(max_i2, max_i1 + static_cast<long long>(a[2]) * b[i]);
            }
            if (i >= 1) {
                max_i1 = max(max_i1, max_i0 + static_cast<long long>(a[1]) * b[i]);
            }
            max_i0 = max(max_i0, static_cast<long long>(a[0]) * b[i]);
        }
        return max_i3;
    }
};