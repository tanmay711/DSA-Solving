class MinStack {
public:
    stack<pair<int,int>>st;
// its upto us how we create minstack here we can have pairs in which we will have first element as top and min number as we need minnumber in ques

// top is pair like pair<int, int> this whole is pair
    MinStack() {
        
    }
    void push(int value)
    {
        if(st.empty())
        {
            st.push({value, value});
        }
        else{
            int minval= min(value, st.top().second);
            st.push({value, minval});
        }
    }
        void pop()
        {
            st.pop();
        }
        int top()
        {
            return st.top().first;
        }
        int getMin()
        {
            return st.top().second;
        }

    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */