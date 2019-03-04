class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(sMin.empty()){
            sMin.push(x);
        }
        else if(x < sMin.top()){
            sMin.push(x);
        }
        else sMin.push(sMin.top());
        sData.push(x);
        return;
    }
    
    void pop() {
        if(sData.empty()) throw runtime_error("Empty Stack!");
        sData.pop();
        sMin.pop();
    }
    
    int top() {
        return sData.top();
    }
    
    int getMin() {
        return sMin.top();
    }
    private:
    stack<int>sData;
    stack<int>sMin;
};