class Solution {
public:
    int convertTime(string current, string correct) {
        int h1 = stoi(current.substr(0,2));
        int m1 = stoi(current.substr(3,2));

        int h2 = stoi(correct.substr(0,2));
        int m2 = stoi(correct.substr(3,2));

        int start = h1*60+m1;
        int end = h2*60+m2;
        int diff = end-start;
        int ans=0;
        ans = diff/60;
        diff = diff%60;

        ans += diff/15;
        diff = diff%15;

        ans += diff/5;
        diff = diff%5;
        ans+= diff;
        return ans;
    }
};