class Solution {
public:
    int m,n;
    long long dfs(int r, int c, vector<vector<int>>& grid)
    {
        if(r<0 || r>=m || c<0 || c>=n || grid[r][c]==0)
        {
            return 0;
        }
        long long current_val = grid[r][c];
        grid[r][c]= 0;
        long long left = dfs(r,c-1, grid);
        long long right = dfs(r,c+1, grid);
        long long down = dfs(r+1, c,grid);
        long long up =dfs(r-1, c, grid);
        return current_val + left + right+ down+up;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]>0)
                {
            
                long long island_sum = dfs(i,j,grid);
                if(island_sum % k ==0)
                {
                    count++;
                }
                }
            }
        }
        return count;
    }
};