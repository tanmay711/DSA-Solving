class Solution {
public:
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int num(string s)
    {
        int month =stoi(s.substr(0,2));
        int day = stoi(s.substr(3,2));
        int count=0;
        for(int i=0;i<month-1;i++)
        {
            count+=days[i];
        }
        return count+day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int a_alice = num(arriveAlice);
        int l_alice = num(leaveAlice);
        int a_bob = num(arriveBob);
        int l_bob = num(leaveBob);

        int start = max(a_alice,a_bob);
        int end = min(l_alice,l_bob);
        if(start>end)
        {
            return 0;
        }
        return end-start+1;
    }
};