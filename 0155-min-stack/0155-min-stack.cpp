class MinStack {
public:
    stack<pair<int, int>> st; //{val, minele}
    MinStack() {}
    
    void push(int val) {
        if(!st.empty() && st.top().second < val) st.push({val, st.top().second});
        else st.push({val, val});
    }
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */