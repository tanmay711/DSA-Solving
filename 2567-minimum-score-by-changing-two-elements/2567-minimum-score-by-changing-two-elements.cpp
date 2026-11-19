class Solution {
public:
    int minimizeSum(vector<int>& nums) {
// we will try to make 2 no. equal so that low will always be 0, now for high to be minimum we can 
    int n = nums.size();
    sort(nums.begin(),nums.end());

    return min({
        (nums[n-3] - nums[0]), (nums[n-1] - nums[2]), (nums[n-2]-nums[1])}
    );
    }
};