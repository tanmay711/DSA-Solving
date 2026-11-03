class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        int last = nums[n-1];
        int count=0;
        for(int i=0;i<n;i++)
        {
            count += abs(nums[i]-last);
        }
        return count;
    }
};