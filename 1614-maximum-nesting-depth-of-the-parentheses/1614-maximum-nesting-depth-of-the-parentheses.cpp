class Solution {
public:
    int maxDepth(string s) {
        int ans =0;
        int inside =0;
        for(char ch : s)
        {
            if(ch == '(')
            {
                inside++;
                ans = max(ans, inside);
            }
            else if(ch ==')')
            {
                inside--;
            }
        }
        return ans;
    }
};