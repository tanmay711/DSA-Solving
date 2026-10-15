class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> res(n,0);
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++)
        {
            while(st.empty()==0 && temperatures[i] > st.top().first)
            {
                int stackIndex = st.top().second;
                st.pop();
                res[stackIndex] = i-stackIndex;
            }
            st.push({temperatures[i],i});
        }
        return res;
    }
};