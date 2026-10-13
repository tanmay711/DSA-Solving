class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> squares;


        for(int x:nums)
        {
            squares.push_back(1LL * x * x);
        }
        int n=squares.size();
        sort(squares.begin(),squares.end());
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(i < n/2)
            {
                ans -= squares[i];
            }
            else
            {
                ans += squares[i];
            }
        }
        return ans;
        
    }
};