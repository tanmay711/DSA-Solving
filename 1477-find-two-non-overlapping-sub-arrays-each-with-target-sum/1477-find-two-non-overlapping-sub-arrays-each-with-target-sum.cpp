class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int k = 9999999;
        vector<int> great(n,k);
        int left = 0;
        int sum =0;
        int ans=k;
        int right;
        for(right=0;right<n;right++)
        {
            sum+= arr[right];
            while(sum >target)
            {
                sum -= arr[left];
                left++;
            }
            if(sum==target)
            {
                int len = right-left+1;
                if(left>0 && great[left-1]!=k)
                {
                    ans = min(ans, len + great[left-1]);
                }
                if(right==0)
                {
                    great[right] = len;
                }
                else
                {
                    great[right] = min(great[right-1],len);
                }
            }
            else
            {
                if(right>0)
                {
                    great[right] = great[right-1];
                }
            }
        }

        return ans == k ? -1:ans;
    }
};