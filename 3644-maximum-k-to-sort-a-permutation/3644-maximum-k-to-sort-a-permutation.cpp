class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(i== nums[i])
            {
                continue;
            }
            else if( i != nums[i])
            {
                k = k&nums[i];
            }
        }
        return max(k,0);
    }
};