class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int last2 = 1;
        int last1=2;
        for(int i=3;i<=n;i++)
        {
            int curr = last2+last1;
            last2=last1;
            last1=curr;
        }
        return last1;
    }
};