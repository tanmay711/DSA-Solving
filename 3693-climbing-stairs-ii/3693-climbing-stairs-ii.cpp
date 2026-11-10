class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        for(int i=1;i<=n;i++)
        {
            int cost = INT_MAX;
            int j=i-1;
            if(j>=0)
            {
                cost = min(cost, dp[j]+ costs[i-1] + (i-j)*(i-j));
            }
            j = i-2;
            if(j>=0)
            {
                cost = min(cost,dp[j] + costs[i-1] + (i-j)*(i-j));
            }
            j = i-3;
            if(j>=0)
            {
                cost = min(cost, dp[j] + costs[i-1] + (i-j)*(i-j));
            }

            dp[i] = cost;
        }
        return dp[n];
    }
};