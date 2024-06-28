#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <climits>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

int scaledN = 1, N, M, K;
const int DIV = 1'000'000'007;

void ChangeNum(vector<long long>& Segment, int b, int c)
{
    b += scaledN;
    Segment[b] = c;
    for (b /= 2; b >= 1; b /= 2)
    {
        Segment[b] = Segment[2 * b] * Segment[2 * b + 1] % DIV;
    }
}

int GetMult(vector<long long>& Segment, int b, int c)
{
    b += scaledN;
    c += scaledN;

    int ans = 1;
    while (b <= c)
    {
        if (b % 2 == 1) ans = ans * Segment[b++] % DIV;
        if (c % 2 == 0) ans = ans * Segment[c--] % DIV;

        b /= 2;
        c /= 2;
    }

    return ans;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    while (scaledN < N)
    {
        scaledN *= 2;
    }

    vector<long long> Segment(scaledN * 2, 1);

    for (int i = 0; i < N; i++)
    {
        cin >> Segment[i+ scaledN];
    }

    for (int i = scaledN - 1; i > 0; i--)
    {
        Segment[i] = Segment[2 * i] * Segment[2 * i + 1] % DIV;
    }

    for (int i = 0; i < M + K; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1)
        {
            ChangeNum(Segment, b-1, c);
        }
        else
        {
            cout << GetMult(Segment, b-1, c-1) << "\n";
        }
    }

    return 0;
}