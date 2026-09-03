class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        vector<bool> composite(n / 2, false);

        for (int i = 3; 1LL * i * i < n; i += 2) {
            if (!composite[i / 2]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    composite[j / 2] = true;
                }
            }
        }

        int count = 1;  // number 2

        for (int i = 3; i < n; i += 2) {
            if (!composite[i / 2])
                count++;
        }

        return count;
    }
};