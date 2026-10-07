class Solution {
public:
    

    bool isvalid(string s)
    {
        int balance=0;
        for(int i=0;i<s.size();i++)
        {
        if(s[i]=='(')
        {
            balance++;
        }
        else{
            if(s[i]==')')
            {
                balance--;
                if(balance<0){ return false;}
            }
        }
        }
        return balance==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        queue<string>q;
        unordered_set<string> visited;
        q.push(s);
        visited.insert(s);
        bool found=false;
        while(q.empty()==0)
        {
            int size = q.size();
            while(size--)
            {
                string curr = q.front();
                q.pop();

                if(isvalid(curr))
                {
                    ans.push_back(curr);
                    found = true;
                }
                if(found == true)
                {
                    continue;
                }
                int n=curr.size();
                for(int i=0;i<n;i++)
                {
                    if(curr[i]!='(' && curr[i]!=')')
                    {
                        continue;
                    }
                    string next = curr.substr(0,i) + curr.substr(i+1);

                    if(visited.find(next)==visited.end())
                    {
                        visited.insert(next);
                        q.push(next);
                    }
                }

            }
            if(found) break;
        }
        return ans;
    }
};