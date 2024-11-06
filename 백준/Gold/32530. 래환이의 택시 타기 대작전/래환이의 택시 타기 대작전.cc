#include <bits/stdc++.h>

using namespace std;

int N;

struct Time
{
    Time(int h, int m) : hour(h), minute(m) { };

    int hour;
    int minute;

    bool operator < (const Time& Other)
    {
        if (hour == Other.hour) return minute < Other.minute;
        return hour < Other.hour;
    }

    void operator += (int m)
    {
        minute += m;
        if (60 <= minute)
        {
            hour++;
            minute -= 60;
        }
    }
};

int makeHour(const string& time)
{
    int h = time[0] - '0';
    h *= 10;
    h += time[1] - '0';

    return h;
}

int makeMinute(const string& time)
{
    int m = time[3] - '0';
    m *= 10;
    m += time[4] - '0';

    return m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);  

    cin >> N;

    vector<Time> times;
    for (int i = 0; i < N; i++)
    {
        string time;
        cin >> time;

        times.push_back(Time(makeHour(time), makeMinute(time)));
    }

    sort(times.begin(), times.end());
    int ans = 0;

    for (int i = 0; i < N;)
    {
        auto current = times[i];
        current += 20;

        int next = i + 1;
        while(next < N)
        {
            if (current < times[next]) break;
            next++;
        }

        ans++;
        i = next;
    }

    cout << ans;

    return 0;
}