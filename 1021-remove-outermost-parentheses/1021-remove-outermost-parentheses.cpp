class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        string curr = "";
        int open=0;
        int close =0;
        for(char ch:s)
        {
            if(ch == '(')
            {
                open++;
            }
            else
            {
                close++;
            }
            curr.push_back(ch);
            if(open == close)
            {
                if(curr.size()>=4)
                {
                    ans += curr.substr(1,curr.size()-2);
                }
                curr = "";
                open = close=0;
            }
        }
        return ans;
    }
};