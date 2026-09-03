class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd_small = INT_MAX;
        for(int x:nums1)
        {
            if(x%2!=0)
            {
                odd_small = min(odd_small, x);
            }
        }
        if(odd_small == INT_MAX)
        {
            return true;

        }
        for(int y : nums1)
        {
            if(y%2==0 && y<odd_small)
            {
                return false;
            }
        }
        return true;
    }
};