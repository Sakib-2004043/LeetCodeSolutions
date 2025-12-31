class MyQueue {
public:
    stack<int> stackMain, stackHelper;
    void push(int x) {
        stack<int> stackHelper;
        while (!stackMain.empty()) {
            stackHelper.push(stackMain.top());
            stackMain.pop();
        }
        stackMain.push(x);
        while (!stackHelper.empty()) {
            stackMain.push(stackHelper.top());
            stackHelper.pop();
        }
    }
    int pop() {
        int x = stackMain.top();
        stackMain.pop();
        return x;
    }
    int peek() { return stackMain.top(); }
    bool empty() { return stackMain.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */