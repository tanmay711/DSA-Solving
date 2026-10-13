class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> last_occ;
        for(int i=0;i<s.size();i++)
        {
            last_occ[s[i]]=i;
        }
        stack<char> st;
        vector<bool> vis(26,false);
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];
            if(vis[ch-'a'])
            {
                continue;
            }

            while(st.empty()==0 && st.top()>ch && last_occ[st.top()]>i)
            {
                vis[st.top()-'a']=false;
                st.pop();
            }
            st.push(ch);
            vis[ch-'a'] = true;
        }
        string ans = "";
        while(st.empty()==0)
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};