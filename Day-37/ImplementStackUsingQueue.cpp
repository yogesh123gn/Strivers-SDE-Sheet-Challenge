/* Problem : Implement stack using queue
Time Complexity : O(N)
Space Complexity : O(N)
*/

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        int sz=q.size();
        q.push(x);
        while(sz--){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int result=top();
        q.pop();
        return result;
    }
    
    int top() {
        return q.front();
    }
    
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
