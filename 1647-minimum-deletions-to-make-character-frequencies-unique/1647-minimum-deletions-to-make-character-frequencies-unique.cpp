class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mapp;
        for(char ch:s)
        {
            mapp[ch]++;
        }
        unordered_set<int>used;
        int ans=0;

        for(auto [ch, f] : mapp)
        {
            while(f>0 && used.count(f))
            {
                f--;
                ans++;
            }
            if(f>0)
            {
                used.insert(f);
            }
        }
        return ans;
    }
};