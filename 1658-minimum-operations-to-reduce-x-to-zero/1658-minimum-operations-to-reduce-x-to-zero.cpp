// find max subarray with target as totalsum  - x;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalsum=0;
        for(int num : nums)
        {
            totalsum += num;
        }
        int target = totalsum-x;
        if(target < 0)
        {
            return -1;
        }
        if(target==0)
        {
            return n;
        }
        int left=0;
        int sum =0;
        int maxlen = -1;
        for(int right = 0; right<n;right++)
        {
            sum += nums[right];
            while(sum > target)
            {
                sum -= nums[left];
                left++;
            }
            if(sum == target)
            {
                maxlen = max(maxlen , right - left+1);
            }
        }
        if(maxlen == -1)
        {
            return -1;
        }
        return n - maxlen;
    }
};