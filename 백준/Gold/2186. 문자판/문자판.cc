#include <stdio.h>
#include <string>
#include <cstring>
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

int N, M, K;
const int MAX = 100;
string word;

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };
int DP[MAX][MAX][80] = { {{-1,}} };

int DFS(vector<vector<char>>& Board, int y, int x, int depth)
{
    if (DP[y][x][depth] != -1) return DP[y][x][depth];
    if (depth == (int)word.size()-1)
    {
        return 1;
    }

    DP[y][x][depth] = 0;
    for (int i = 0; i < 4; i++)
    {
        int newY = y;
        int newX = x;

        for (int k = 0; k < K; k++)
        {
            newY += dy[i];
            newX += dx[i];

            if (newY < 0 || newY >= N || newX < 0 || newX >= M) break;
            if (Board[newY][newX] != word[depth+1]) continue;

            DP[y][x][depth] += DFS(Board, newY, newX, depth + 1);
        }
    }

    return DP[y][x][depth];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    vector<vector<char>> Board(N, vector<char>(M));
    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Board[i][j];
        }
    }

    cin >> word;

    memset(DP, -1, sizeof(DP));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Board[i][j] != word[0]) continue;

            ans += DFS(Board, i, j, 0);
        }
    }

    cout << ans;

    return 0;
}