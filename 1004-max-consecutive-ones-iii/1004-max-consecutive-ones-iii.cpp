class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int right= 0;
        int maxlen=0;
        int zero=0;
        for(right =0;right<nums.size();right++)
        {
            if(nums[right] ==0)
            {
                zero++;
            }
            while(zero>k)
            {
                if(nums[left]==0)
                {
                    zero--;
                    
                }
                left++;
            }
            int len = right-left+1;
            maxlen = max(maxlen, len);
        }
        return maxlen;
    }
};