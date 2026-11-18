class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        char ch = s[0];
        int count=0;
        int changes=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==ch)
            {
                count++;
                continue;
            }

            //if not euqal to
            if(count%2==0)
            {
                count=1;

            }
            else // not equal and count not even so we need to make change now
            {
                changes+=1;
                count=0;
            }

            ch = s[i];

        }
                      return changes;
    }
  
};