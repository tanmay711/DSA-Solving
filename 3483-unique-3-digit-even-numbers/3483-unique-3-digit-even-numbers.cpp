class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count[10] ={};
        for(int c:digits)
        {
            count[c]++;
        }
        vector<int>ans;
        for(int i=1;i<=9;i++)
        {
            for(int j=0;j<=9;j++)
            {
                for(int k=0;k<=8;k+=2)
                {
                    count[i]--;
                    count[j]--;
                    count[k]--;

                    if(count[i]>=0 && count[j]>=0 && count[k]>= 0)
                    {
                        ans.push_back(i*100+j*10+k);



                    }
                        count[i]++;
                        count[j]++;
                        count[k]++;
                }
            }
        }
        int cnt=0;
        for(int cc:ans)
        {
            cnt++;
        }
        return cnt;

    }
};