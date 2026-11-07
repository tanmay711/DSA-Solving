class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
       int n = matrix.size();
       for(int i=0;i<n;i++)
       {
            vector<bool>vis(n+1,false);
            for(int j=0;j<n;j++)
            {
                int num = matrix[i][j];
                if(vis[num])
                {
                    return false;
                }
                vis[num]= true;
            }
       } 
       for(int j=0;j<n;j++)
       {
          vector<bool>vis(n+1,false);
        for(int i=0;i<n;i++)
        {
            
            int num = matrix[i][j];
            if(vis[num])
            {
                return false;
            }
            vis[num] = true;
        }
       }
       return true;
    }
};