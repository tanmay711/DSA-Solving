class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0, left=0, right=0;
        while(right < nums.size()-1)
        {
            int fartest=0;
            for(int i=left; i<=right;i++)
            {
                fartest = max(fartest, i+nums[i]);
            }
            left = right+1;
            right = fartest;
            jump+=1;
        }
        return jump;
    }
};