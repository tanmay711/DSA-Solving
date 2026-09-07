class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool>isused;
    void backtract(vector<int>& nums)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(isused[i])
            {
                continue;
            }
            isused[i] = true;
            temp.push_back(nums[i]);
            backtract(nums);

            temp.pop_back();
            isused[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
      isused.resize(nums.size(),false);
      backtract(nums);
      return ans;  
    }
};