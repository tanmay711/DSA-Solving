class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size()) 
        {
        return {};
        }
        unordered_map<char, int> pCount, sCount;
        for(int i=0;i<p.size();i++)
        {
            sCount[s[i]]++;
            pCount[p[i]]++;
        }
        vector<int> ans;
        if(pCount==sCount)
        {
            ans.push_back(0);
        }
        int left=0;
        for(int right=p.size();right<s.size();right++)
        {
            sCount[s[right]]++;
            sCount[s[left]]--;

            if(sCount[s[left]]==0)
            {
                sCount.erase(s[left]);
            }
            left++;
            if(sCount==pCount)
            {
                ans.push_back(left);
            }
        }
        return ans;
    }
};