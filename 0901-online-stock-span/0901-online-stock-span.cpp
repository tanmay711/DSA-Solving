class StockSpanner {
public:
    stack<pair<int,int>>st; // first is val second is index;
    int index = -1;
    
    int next(int price) {
        index++;
        while(st.empty()==0 && st.top().first <=price )
        {
            st.pop();
        }
        int ans = index - (st.empty() ? -1 : st.top().second);
        st.push({price, index});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */