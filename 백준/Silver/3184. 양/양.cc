#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int R, C;

vector<vector<bool>> visited;
vector<string> board;

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };


pair<int,int> Bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({ i,j });

    int sheep = 0;
    int wolf = 0;

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newY = y + dy[i];
            int newX = x + dx[i];

            if (newY < 0 || newY >= R || newX < 0 || newX >= C) continue;
            if (visited[newY][newX]) continue;
            if (board[newY][newX] == '#') continue;

            visited[newY][newX] = true;
            q.push({ newY, newX });

            if (board[newY][newX] == 'o') sheep++;
            else if (board[newY][newX] == 'v') wolf++;
        }
    }

    if (sheep <= wolf) sheep = 0;
    else wolf = 0;

    return { sheep, wolf };
}



int main() 
{
    INPUT_OPTIMIZE;

    cin >> R >> C;

    board.resize(R);
    visited.resize(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++)
    {
        cin >> board[i];
    }


    int sheep = 0, wolf = 0;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (visited[i][j]) continue;

            auto [s, w] = Bfs(i, j);

            sheep += s;
            wolf += w;
        }
    }

    cout << sheep << " " << wolf;

    return 0;
} 