/* Problem : Implement Queue using Two Stack
Time Complexity : O(1)
Space Complexity : O(2N)
*/

class MyQueue {
    
private:
    stack<int> input,output;
public:
    void push(int x) {
        input.push(x);
    }
    int pop() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int val=output.top();
        output.pop();
        return val;
    } 
    int peek() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    } 
    bool empty() {
        return input.empty() && output.empty();
    }
};

