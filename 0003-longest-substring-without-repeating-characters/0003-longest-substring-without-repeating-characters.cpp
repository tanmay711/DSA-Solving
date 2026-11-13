class Solution {
public:
// last (hash) stored the latest occurance of that index
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256,-1);
        int left=0;
        int right=0;
        int maxlen=0;
        int n=s.size();
        while(right<n)
        {
            if(last[s[right]]!=-1)
            {
                if(last[s[right]]>=left)
                {
                    left = last[s[right]] +1;
                }
            }
            int len = right-left+1;
            maxlen = max(maxlen, len);
            last[s[right]] = right;
            right++;
        }
        return maxlen;
    }
};