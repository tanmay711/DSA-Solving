class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> minn(n);
        minn[n-1] = nums[n-1];
        for(int i=n-2; i>=0;i--)
        {
            minn[i] = min(nums[i],minn[i+1]);
        }
        int maxy=0;
        for(int i=0;i<n;i++)
        {
            maxy = max(maxy, nums[i]);

            int instability = maxy - minn[i];

            if(instability <= k)
            {
                return i;
            }
        }
        return -1;
    }
};