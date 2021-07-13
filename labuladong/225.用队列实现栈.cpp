/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    queue<int> q;
    int top_elem;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        top_elem = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp;
        if (q.size() == 1) {
            temp = q.front();
            q.pop();
            return temp;
        }
        
        for (int i=0; i<q.size()-2; i++) {
            temp = q.front();
            q.pop();
            q.push(temp);
        }
        top_elem = q.front();
        q.pop();
        q.push(top_elem);
        temp = q.front();
        q.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        return top_elem;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

