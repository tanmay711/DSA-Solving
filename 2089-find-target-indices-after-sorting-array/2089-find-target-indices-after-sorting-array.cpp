class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count=0;
        int rest=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<target)
            {
                count++;
            }
            else if(nums[i]== target)
            {
                rest++;
            }
        }
        for(int i=count;i<count+rest;i++)
        {
            ans.push_back(i);
        }
        return ans;
    }
};