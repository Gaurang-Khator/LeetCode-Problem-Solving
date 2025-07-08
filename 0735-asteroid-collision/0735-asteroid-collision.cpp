class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> res;
        for(int i=0; i<asteroids.size(); i++) {
            if(!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                if(st.top() == abs(asteroids[i])){
                    st.pop();
                }
                else if(st.top() < abs(asteroids[i])) {
                    st.pop();
                    i--;
                }
            } else {
                st.push(asteroids[i]);
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};