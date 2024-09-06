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
#include <list>
#include <bitset>

using namespace std;

int R, C;
int ans = 1;
vector<vector<char>> board;

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

vector<int> Cnt(26, 0);

void dfs(int y, int x, int depth)
{
    ans = max(ans, depth);
    for (int i = 0; i < 4; i++)
    {
        int newY = y + dy[i];
        int newX = x + dx[i];

        if (newY < 0 || newY >= R || newX < 0 || newX >= C) continue;
        if (Cnt[board[newY][newX] - 'A'] > 0) continue;

        Cnt[board[newY][newX] - 'A']++;
        dfs(newY, newX, depth + 1);
        Cnt[board[newY][newX] - 'A']--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    
    board.resize(R, vector<char>(C));
    for (int i = 0; i < R; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < C; j++)
        {
            board[i][j] = input[j];
        }
    }

    Cnt[board[0][0]-'A'] = 1;
    dfs(0, 0, 1);

    cout << ans;

    return 0;
}