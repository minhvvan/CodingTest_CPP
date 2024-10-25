#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> dices;
vector<int> faced = { 0, 6, 4, 5, 2, 3, 1 };

int GetMaxNum(int bottom, int top)
{
    vector<bool> temp(7, true);

    temp[bottom] = false;
    temp[top] = false;

    for (int i = 6; i > 0; i--)
    {
        if (temp[i]) return i;
    }

    return -1;
}

int GetIdx(vector<int>& dice, int num)
{
    for (int i = 1; i <= 6; i++)
    {
        if (num == dice[i]) return i;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);
    
    cin >> N;

    dices.resize(N+1, vector<int>(7));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            cin >> dices[i][j];
        }
    }

    int ans = 0;
    //아래가 정해지면 쭉쭉 정해짐
    for (int i = 1; i <= 6; i++)
    {
        int current = 0;
        //i번 면이 아래로
        int top = dices[1][faced[i]];
        current += GetMaxNum(dices[1][i], top);

        for (int j = 2; j <= N; j++)
        {
            int bottomIdx = GetIdx(dices[j], top);
            top = dices[j][faced[bottomIdx]];
            
            current += GetMaxNum(dices[j][bottomIdx], top);
        }

        ans = max(ans, current);
    }

    cout << ans;

    return 0;
}