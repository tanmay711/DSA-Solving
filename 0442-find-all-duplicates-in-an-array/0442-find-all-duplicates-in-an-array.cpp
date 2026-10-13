/*
We use the nums array itself instead of an unordered set, mapping each number to index n-1 and marking it negative to identify duplicates. */

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int n = abs(nums[i]);
            if(nums[n-1] <0)
            {
                ans.push_back(n);
            }
            nums[n-1] = -nums[n-1];
        }
        return ans;

    }
};