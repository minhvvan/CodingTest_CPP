#include <bits/stdc++.h>

using namespace std;

float N;
vector<vector<int>> Cards;

void makeComb(vector<vector<int>>& out, vector<int>& temp, int idx)
{
    if (temp.size() == 3)
    {
        out.push_back(temp);
        return;
    }

    for (int i = idx; i < 5; i++)
    {
        temp.push_back(i);
        makeComb(out, temp, i + 1);
        temp.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(1);
    
    cin >> N;

    Cards.resize(N+1, vector<int>(5));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> Cards[i][j];
        }
    }

    vector<vector<int>> Comb;
    vector<int> temp;
    makeComb(Comb, temp, 0);

    int maxNum = 0;
    int maxIdx = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0 ; j < Comb.size(); j++)
        {
            int a = Cards[i][Comb[j][0]];
            int b = Cards[i][Comb[j][1]];
            int c = Cards[i][Comb[j][2]];

            int digit = (a + b + c) % 10;
            if (digit >= maxNum)
            {
                maxNum = digit;
                maxIdx = i;
            }
        }
    }

    cout << maxIdx;

    return 0;
}