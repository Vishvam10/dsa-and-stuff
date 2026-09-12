class MyQueue {
private :
    stack<int> st1, st2;

    void move() {
        if(st2.empty()) {
            while(!st1.empty()) st2.push(st1.top()), st1.pop();
        }
    }

public:
    MyQueue() {
        // [1, 2, 3, 4, 5]

        // push : [1] [ ]
        // push : [1, 2] [ ]
        // push : [1, 2, 3] [ ]
        // pop  : [1, 2, 3, 4] [ ]
        //      : [] [4, 3, 2, 1]
        //      : [] [3, 2, 1]
        // push : [5] [3, 2, 1]
        // pop  : [5] [2, 1]
        // pop  : [5] [1]
        // pop  : [5] [ ]
        // pop  : [ ] [5]
        //      : [ ] [ ]
    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        move();
        int ele = st2.top();
        st2.pop();
        return ele;
    }

    int peek() {
        move();
        return st2.top();
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
