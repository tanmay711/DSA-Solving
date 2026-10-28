class Solution {
public:
    int balancedStringSplit(string s) {
        int countR=0;
        int countL=0;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='L') countL++;
            if(s[i]=='R') countR++;
            if(countR==countL)
            {
                ans++;
            }


        }
        return ans;
    }
};