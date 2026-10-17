/*
1. Calculate the digit sum of each number using getDigitSum().

2. Copy nums into afterSorted and sort it by digit sum in ascending order, breaking ties by the smaller number.

3. Store each number's current index in the valToIdx hashmap.

4. Traverse nums and compare each element with its expected value in afterSorted.

5. If they differ, find the expected value's current index using valToIdx, swap the two elements, and update their indices in the hashmap.

6. Increment swapCount for every swap and return it after processing the entire array.
*/

class Solution {
public:
    int digitsum(int num)
    {
        int sum=0;
        while(num>0)
        {
            sum+= num%10;
            num /=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> aftersort(nums);
        auto lamda = [this](int num1, int num2)
        {
            int num1digitsum = digitsum(num1);
            int num2digitsum = digitsum(num2);
            if(num1digitsum != num2digitsum)
            {
                return num1digitsum < num2digitsum; // if true smaller is considered
            }
            return num1<num2; // if both equal take smaller num
        };
        sort(aftersort.begin(),aftersort.end(),lamda);

        unordered_map<int,int> pos;
        for(int i=0;i<n;i++)
        {
            pos[nums[i]]=i;
        }

        int swapcount =0;
        for(int i=0;i<n;i++)
        {
            int expectedval = aftersort[i];
            int currval = nums[i];

            if(expectedval == currval)
            {
                continue;
            }
            int idx = pos[expectedval];
            swap(nums[i],nums[idx]); // swap curr number with the expected number

            pos[expectedval] = i;
            pos[currval] = idx; // reflect changes in map also
            swapcount++;

        }
        return swapcount;
    }
};