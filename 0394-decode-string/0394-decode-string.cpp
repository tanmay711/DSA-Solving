class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=']')
            {
                st.push(string(1,s[i]));
            }
            else
            {
                string substr = "";
                while(st.top()!= "[")
                {
                    substr = st.top()+substr;
                    st.pop();
                }
                st.pop(); // remove [
                string k="";
                while(st.empty()==0 && isdigit(st.top()[0]))
                {
                    k = st.top()+k;
                    st.pop();
                }
                string temp ="";
                for(int i=0;i<stoi(k);i++)
                {
                    temp += substr;

                }
                st.push(temp);
            }
        }
        string ans = "";
        while(st.empty()==0)
        {
            ans  = st.top()+ans;
            st.pop();
        }
        return ans;

    }
};