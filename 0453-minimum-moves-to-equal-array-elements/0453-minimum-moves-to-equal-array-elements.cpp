class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count=0;
        sort(nums.begin(),nums.end());
        int min = nums[0];
        for(int i=0;i<nums.size();i++)
        {
            count += nums[i]-min;
        }
        return count;
    }
};