class Solution {
public:
    int mod = 1e9+7;
    int solve(int i, int j, int prev, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp,int n,int m)
    {
        if(i<0 || i==n || j<0 || j==m)
        {
            return 0;
        }
        if(i==n-1 && j==m-1)
        {
            return 1;
        }
        if(dp[i][j][prev+1] != -1) // prev+1 cause if prev is -1 then invalid
        {
            return dp[i][j][prev+1];
        }
        int right=0;

        int down =0;
        if(grid[i][j]==1) // mirror
        {
            if(prev ==0)
            {
                down = solve(i+1, j, 1, grid, dp, n ,m);
            }
            else
            {
                right = solve(i,j+1, 0, grid, dp, n, m);
            }
        }

        else
        {
            down = solve(i+1,j,1,grid,dp,n,m);
            right = solve(i,j+1, 0, grid, dp, n, m);
        }
        return dp[i][j][prev+1] = (right+down) %mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(3,-1)));

        return solve(0,0,-1,grid,dp,n,m);
    }

};