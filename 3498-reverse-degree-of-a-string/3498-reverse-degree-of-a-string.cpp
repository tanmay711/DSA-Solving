class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char, int> mapp;
        for(char c = 'z' ; c>= 'a' ; c--)
        {
            mapp[c] = 'z' - c +1;
        }
        int ans=0;
        int pos =1;
        for(char c : s)
        {
            ans += mapp[c] * pos;
            pos++;
        }
        return ans;
    }
};