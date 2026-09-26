class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>map;
        for(auto &it : knowledge)
        {
            map[it[0]] = it[1];
        }
        string ans= "";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]== '(')
            {
                string key = "";
                i++;
                while(s[i]!= ')')
                {
                    key += s[i];
                    i++;
                }
                if(map.find(key)!= map.end())
                {
                    ans += map[key];
                }
                else
                {
                    ans += "?";
                }
            }
            else
            {
                ans += s[i];
            }
        }
        return ans;
    }
};