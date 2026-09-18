class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();

        int ans=0;
        int left=0;
        int right= n-1;

        while(left<right)
        {
            int width = right-left;
            int heightt = min(height[left],height[right]);
            ans = max(ans, width*heightt);
            if(height[right]>height[left])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return ans;
    }
};