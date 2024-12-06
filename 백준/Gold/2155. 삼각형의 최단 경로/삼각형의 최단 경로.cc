#include <bits/stdc++.h>

using namespace std;

long long A, B;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> A >> B;

    if (A > B) swap(A, B);

    //row로는 1씩 차이가 나고
    //다음 행으로 이동하는 경우는 2,4,6,8...
    //가장 짧은 경로가 되려면 행이동을 하는게 유리함
    //시작은 1,3,5...

    //A,B가 몇 층 몇 칸인지 구할 수 있음
    //현재 홀수칸에서만 다음층으로 이동할 수 있음
    //홀수칸은 다음칸에서 +1에 대응됨

    pair<int, int> Apos;
    pair<int, int> Bpos;

    vector<int> rowIncrease(1);

    {
        int temp = 1;
        int inc = 1;
        int depth = 1;
        rowIncrease.push_back(inc);

        while (temp + inc <= B)
        {
            temp += inc;
            inc += 2;
            rowIncrease.push_back(inc);
            depth++;
            if (temp == B) break;
        }

        int width = B - temp + 1;
        Bpos = { depth, width };
    }

    {
        int temp = 1;
        int depth = 1;
        int row = 1;

        while (temp + rowIncrease[row] <= A)
        {
            temp += rowIncrease[row++];
            depth++;
            if (temp == A) break;
        }

        int width = A - temp + 1;
        Apos = { depth, width };
    }

    int ans = 0;
    while (Apos.first != Bpos.first)
    {
        ans++;

        if (Apos.second % 2 == 0)
        {
            //move in row
            if (Apos.second < Bpos.second)
            {
                A++;
                Apos.second++;
            }
            else
            {
                A--;
                Apos.second--;
            }
        }
        else
        {
            //move across row
            A += rowIncrease[Apos.first] + 1;
            Apos.first++;
            Apos.second++;
        }

    }

    ans += abs(Bpos.second - Apos.second);
    cout << ans;

    return 0;
}