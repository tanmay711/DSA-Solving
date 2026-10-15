class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            unordered_set<int> sett;
            
            for(int j=i;j<nums.size();j++)
            {
                sett.insert(nums[j]);
            

                int count = sett.size();
                ans += count*count;

            }
            
        }
        return ans;
    }
};