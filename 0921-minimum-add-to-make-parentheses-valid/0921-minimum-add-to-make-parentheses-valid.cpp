class Solution {
public:
    int minAddToMakeValid(string s) {
        int answer =0;
        int open =0;
        for(char ch: s)
        {
            if(ch=='(')
            {
                open++;
            }
            else
            {
                if(open>0)
                {
                    open--;
                }
                else
                {
                    answer++;
                }
            }
     
        }
               return answer+open;
    }
};