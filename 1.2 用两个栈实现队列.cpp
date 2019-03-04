/*
232. Implement Queue using Stacks
https://leetcode-cn.com/problems/implement-queue-using-stacks/
*/
##实现方式一：
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        spush.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(spush.empty() && spop.empty())
            throw runtime_error("this queue is empty");
        else if(spop.empty()){
            while(!spush.empty()){
                spop.push(spush.top());
                spush.pop();
            }
        }
        int x = spop.top();
        spop.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if(spush.empty() && spop.empty())
            throw runtime_error("this queue is empty");
        else if(spop.empty()){
            while(!spush.empty()){
                spop.push(spush.top());
                spush.pop();
            }
        }
        return spop.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return spush.empty() && spop.empty();
    }
    private:
    stack<int>spush;
    stack<int>spop;
};

