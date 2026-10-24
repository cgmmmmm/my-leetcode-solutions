struct Date 
{
    int month;
    int day;

    auto operator<=>(const Date&) const = default;
};

class Solution {
public:
    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) 
    {
        Date aa = getDate(arriveAlice);
        Date la = getDate(leaveAlice);
        Date ab = getDate(arriveBob);
        Date lb = getDate(leaveBob);

        if (ab > la || aa > lb) return 0;
        else if (ab == la || lb == aa) return 1;
        
        if (aa < ab) // alice arrive first
        {
            if (la >= lb) // bob leaves first
            {
                return calcDays(ab, lb);
            }
            else // alice leaves first
            {
                return calcDays(ab, la);
            }
        }
        else if (ab < aa) // bob arrives first
        {
            if (la >= lb) // bob leaves first
            {
                return calcDays(aa, lb);
            }
            else // alice leaves first
            {
                return calcDays(aa, la);
            }
        }
        else if (aa == ab) // both arrive at the same day
        {
            if (la >= lb) // bob leaves first
            {
                return calcDays(ab, lb);
            }
            else // alice leaves first
            {
                return calcDays(aa, la);
            }
        }

        return 0;
    }

    Date getDate(const std::string& date)
    {
        int mm = (date[0] - '0') * 10 + (date[1] - '0');
        int dd = (date[3] - '0') * 10 + (date[4] - '0');

        return {mm, dd};
    }

    int calcDays(const Date& arrive, const Date& leave)
    {
        if (arrive.month == leave.month) return leave.day - arrive.day + 1;

        int m = arrive.month;
        int d = months[m++] - arrive.day + 1;
        while (m < leave.month)
        {
            d += months[m++];
        }
        d += leave.day;

        return d;
    }
};