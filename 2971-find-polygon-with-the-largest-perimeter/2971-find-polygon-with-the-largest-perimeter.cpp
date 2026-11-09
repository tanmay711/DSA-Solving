class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long totalsum=0;
        for(int x:nums)
        {
            totalsum+=x;
        }
        for(int i=n-1;i>=2;i--)
        {
            long long remain = totalsum - nums[i];

            if(remain>nums[i])
            {
                return totalsum;
            }
            totalsum -= nums[i];
        }
        return -1;
    }
 
};