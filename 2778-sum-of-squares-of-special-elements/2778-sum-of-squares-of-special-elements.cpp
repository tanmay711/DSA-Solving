class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans=0;
        vector<int> valid;
        int n=nums.size();
        for(int i=1;i<=n;i++)
        {
            
            if(n%i == 0)
            {
                valid.push_back(nums[i-1]);
            }
        }
        int k=valid.size();
        if(k>0)
        {
            for(int i=0;i<k;i++)
            {
                ans += valid[i] * valid[i];
            }
        }
        return ans;
    }
};