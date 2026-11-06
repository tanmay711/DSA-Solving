// https://www.youtube.com/watch?v=iMCVsCcJl_Q&t=278s

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        auto compare = [](vector<int> vec1, vector<int> vec2)
        {
            return vec1[1] < vec2[1];
        };
        sort(logs.begin(),logs.end(), compare);

        int q = queries.size();
        vector<int> result(q);
        vector<pair<int, int>> timeindex(q);
        for(int i=0;i<q;i++)
        {
            timeindex[i] = {queries[i],i};
        }
        sort(timeindex.begin(),timeindex.end()); // by default is sorted based on 0th index here qeury

        unordered_map<int,int> mapp;
        int i=0;
        int j=0;

        for(auto [time, index] : timeindex)
        {
            int start = time-x;
            int end = time;

            // expansion 
            while(j<m && logs[j][1]<=end)
            {
                mapp[logs[j][0]]++;
                j++;
            }

            // shrinking
            while(i<m && logs[i][1] < start)
            {
                mapp[logs[i][0]]--;

                if(mapp[logs[i][0]]==0)
                {
                    mapp.erase(logs[i][0]);
                }
                i++;
            }

            result[index] = n - mapp.size(); 
         }
         return result;

    }
};