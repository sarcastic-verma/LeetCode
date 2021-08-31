class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    
    void push(int val) {
        // if stack is empty then just push the element twice
        if(st.size() == 0)
        {
            st.push(val);
            st.push(val);
            return;
        }
        // else calculate the min from top and new value , push the new val to keep the order correct then push the min so that top of the stack will always have the min value 
        int mn = min(st.top(),val);
        st.push(val);
        st.push(mn);
    }
    
    void pop() {
        // first pop to get the min element 
        st.pop();
        // second pop to get the actual top element 
        st.pop();
    }
    
    int top() {
        // our top contains the min value
        int x = st.top();
        // take out the min value 
        st.pop();
        // get the actual top 
        int top = st.top();
        // push the min value again 
        st.push(x);
        // return the top 
        return top;
    }
    
    int getMin() {
        // our stack will always have the min at the top , according to our algo, so simply return it
        return st.top();
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