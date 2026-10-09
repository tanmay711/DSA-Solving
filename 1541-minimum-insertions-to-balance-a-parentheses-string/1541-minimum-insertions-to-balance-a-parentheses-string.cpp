class Solution {
public:
    int minInsertions(string s) {
        stack<int> st;
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] =='(')
            {
                st.push('(');
            }
            else
            {
                if(i+1 < s.size() && s[i+1] ==')')
                {
                    i++;
                }
                else
                {
                    count++;
                }
                if(st.empty()==0)
                {
                    st.pop();
                }
                else
                {
                    count++;
                }
            }
        }

        return count+= st.size()*2;
    }
};