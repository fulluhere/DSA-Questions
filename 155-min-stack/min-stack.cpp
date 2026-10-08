class MinStack {

private:
    vector<vector<int>>st;
public:
    MinStack() {
    }
    
    void push(int val) {
        int mini = getMin();
        if(st.empty() || mini>val){
            mini = val;
        }

        st.push_back({val, mini});
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.empty() ? -1: st.back()[0];
    }
    
    int getMin() {
        return st.empty()? -1: st.back()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */