#include <stdio.h>
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

int N;
int ans = INT_MAX;

int Sum(vector<pair<int, int>>& Matrices, int Start, int Mid, int End)
{
    return Matrices[Start].first * Matrices[Mid].second * Matrices[End].second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<pair<int, int>> Matrices;
    vector<vector<int>> DP(N, vector<int>(N, INT_MAX));
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        Matrices.push_back({ a,b });
        DP[i][i] = 0;
    }

    for (int i = 1; i < N; i++)
    {
        for (int start = 0; start+i < N; start++)
        {
            int end = start + i;
            for (int mid = start; mid < end; mid++)
            {
                DP[start][end] = min(DP[start][end], DP[start][mid] + DP[mid + 1][end] + Sum(Matrices, start, mid, end));
            }
        }
    }

    cout << DP[0][N-1];

    return 0;
}