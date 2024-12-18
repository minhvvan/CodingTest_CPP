#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> dm = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int convert(int a, int b)
{
    int result = 0;
    for (int i = 0; i < a-1; i++)
    {
        result += dm[i];
    }
    result += b;

    return result;
}

struct Flower
{
    Flower(int a, int b, int c, int d)
    {
        startDay = convert(a, b);
        endDay = convert(c, d);
    }

    int startDay;
    int endDay;

    bool operator < (const Flower& other)
    {
        if (startDay == other.startDay) return endDay > other.endDay;
        return startDay < other.startDay;
    }
};

bool cmp(const Flower& lhs, const Flower& rhs)
{
    return lhs.endDay > rhs.endDay;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N;
    vector<Flower> flowers;
    for (int i = 0; i < N; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        flowers.push_back({ a,b,c,d });
    }

    sort(flowers.begin(), flowers.end());

    int start = convert(3, 1);
    int end = 0;
    int finalDay = convert(11, 30);

    int ans = 0;
    int i = 0;

    while(i < N)
    {
        //이미 범위가 지나감
        if (flowers[i].endDay <= start)
        {
            i++; 
            continue;
        }

        //겹치지 않음
        if (start < flowers[i].startDay)
        {
            cout << 0;
            return 0;
        }

        vector<Flower> temp;
        while (i < N && flowers[i].startDay <= start)
        {
            temp.push_back(flowers[i++]);
        }

        sort(temp.begin(), temp.end(), cmp);

        if (!temp.empty())
        {
            ans++;

            //마지막 날을 지남
            start = temp[0].endDay;
            if (finalDay < temp[0].endDay) break;
        }
    }

    if (start <= finalDay) ans = 0;
    cout << ans;

    return 0;
}