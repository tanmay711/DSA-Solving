class Solution {
public:
    int firstno(vector<int> &nums, int target)
    {

        int ans=-1;
        int low=0;
        int high = nums.size()-1;
        while(low<=high)
        {
            int mid = low + (high-low) /2;
            if(nums[mid]==target)
            {
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low = mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
    int lastno(vector<int> &nums, int target)
    {
        int ans=-1;
        int low=0;
        int high = nums.size()-1;
        while(low<=high)
        {
            int mid = low + (high-low) /2;
            if(nums[mid]==target)
            {
                ans = mid;
                low = mid+1;
            }
            else if(nums[mid]<target)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstno(nums,target);
        int last = lastno(nums,target);
        return {first, last};
    }
};