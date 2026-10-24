class Solution {
public:
    bool isleap(int year)
    {
        if(year%400 ==0)
        {
            return true;
        }
        if(year%100 == 0)
        {
            return false;
        }
        if(year %4 ==0)
        {
            return true;
        }
        else{
            return false;
        }
    }
    int count(string date)
    {
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));

        int days=0;
        for(int y=1;y<year;y++)
        {
            if(isleap(y))
            {
                day+= 366;
            }
            else
            {
                day+=365;
            }
        }

        vector<int> months = {31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31};
        
        if(isleap(year))
        {
            months[1] = 29;
        }

        for(int m=0;m<month-1;m++)
        {
            days+=months[m];
        }

        return days+day;

    }
    int daysBetweenDates(string date1, string date2) {
        int day1 = count(date1);
        int day2 = count(date2);
        return abs(day1-day2);
    }
};