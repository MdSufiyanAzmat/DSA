class MinStack {
public:
   vector<vector<int>> vec;
    MinStack() {
        
    }
    
    void push(int val) {
        int minValue = getMin();
        if(vec.empty() || minValue > val){
            minValue = val;
        }
        vec.push_back({minValue, val});
    }
    
    void pop() {
        vec.pop_back();
    }
    
    int top() {
        return vec.empty() ? -1 : vec.back()[1];
    }
    
    int getMin() {
        return vec.empty() ? -1 : vec.back()[0];
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