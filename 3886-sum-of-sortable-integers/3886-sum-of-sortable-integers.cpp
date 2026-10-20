

class Solution {
public:
  vector<int> buildLPS(vector<int>& pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;

        while (i < n) {
            if (pattern[i] == pattern[len]) {
                lps[i] = ++len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    bool KMPSearch(vector<int>& pattern, vector<int>& text) {
        vector<int> lps = buildLPS(pattern);

        int i = 0, j = 0;

        while (i < text.size()) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }

            if (j == pattern.size()) {
                return true;
            } else if (i < text.size() &&
                       pattern[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return false;
    }

    bool canrotate(vector<int> &vec1, vector<int> &vec2)
    {
        vector<int> text = vec2;
        text.insert(end(text), begin(vec2),end(vec2)); //we need to find whether vec1 is there in vec2 if yes then we can rotate so vec2.insert means kaha insert karna aur kya kaha se lekar kaha tak

        return KMPSearch(vec1, text);
    }

    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int> sorted=nums;
        sort(sorted.begin(),sorted.end());

        int result=0;
        for(int k=1;k<=n;k++)
        {
            if(n%k!=0)
            {
                continue;

            }
            bool isvalid= true;
            for(int start=0;start<n;start+=k)
            {
                vector<int> vec1 (begin(nums)+start, begin(nums)+start+k);
                vector<int> vec2 (begin(sorted)+start, begin(sorted)+start+k);

                if(!canrotate(vec1,vec2))
                {
                    isvalid=false;
                    break;
                }


            }
            if(isvalid)
            {
                result+=k;
            }
        }
        return result;
    }
};

// KMP (Knuth-Morris-Pratt) is a pattern-matching algorithm that efficiently searches for a pattern inside a text. buildLPS() creates an LPS array, where each element stores the length of the longest proper prefix that is also a suffix, helping us avoid rechecking elements after a mismatch. In KMPSearch(), i traverses the text and j traverses the pattern; when elements match, both pointers advance, and when they mismatch, the LPS array tells us where to resume in the pattern without moving i backward. If the entire pattern matches, it returns true; otherwise, it returns false after the text ends. In your code, duplicating vec2 creates vec2 + vec2, allowing KMP to check whether vec1 is a cyclic rotation of vec2.