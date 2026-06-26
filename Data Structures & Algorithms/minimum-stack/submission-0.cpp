class MinStack {
public:
    stack<int> m;
    stack<int> st;

    MinStack() {
        
    }
    
    void push(int val) {
        if (this->m.empty()) {
            this->m.push(val);
        }
        else {
            this->m.push(min(val, this->m.top()));
        }
        this->st.push(val);
    }
    
    void pop() {
        this->m.pop();
        this->st.pop();
    }
    
    int top() {
        return this->st.top();
    }
    
    int getMin() {
        return this->m.top();
    }
};
