class Solution {
public:
    vector<string> ans;
    void solve(string curr, int open, int close, int n)
    {
        if(curr.size() == n*2)
        {
            ans.push_back(curr);
            return;
        }
        if(open<n)
        {
            solve(curr + "(", open+1, close, n);
        }
        if(open>close)
        {
            solve(curr + ")", open, close+1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        solve("",0,0,n);
        return ans;
    }
};