class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n=nums.size();
        int i=0;
        while(i<n)
        {
            int start = nums[i];
            int j=i;

            while(j+1<n && nums[j+1] == nums[j]+1)
            {
                j++;
            }
            if(j==i)
            {
                ans.push_back(to_string(nums[i]));
            }
            else
            {
                ans.push_back(to_string(start) + "->" + to_string(nums[j]));
            }
            i=j+1;
        }
        return ans;
    }
};