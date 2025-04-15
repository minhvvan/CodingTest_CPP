#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M;
vector<vector<char>> board;
vector<vector<bool>> visited;

int white = 0;
int blue = 0;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void Bfs(int i, int j)
{
    queue<pair<int, int>> q;
    visited[i][j] = true;
    q.push({ i,j });

    char target = board[i][j];

    int cnt = 0;
    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        cnt++;

        for (int k = 0; k < 4; k++)
        {
            int newY = y + dy[k];
            int newX = x + dx[k];

            if (newY < 0 || newY >= M || newX < 0 || newX >= N) continue;
            if (visited[newY][newX]) continue;
            if (board[newY][newX] != target) continue;

            visited[newY][newX] = true;
            q.push({ newY, newX });
        }
    }

    if (target == 'W')
    {
        white += cnt * cnt;
    }
    else
    {
        blue += cnt * cnt;
    }
}

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N >> M;

    board.resize(M, vector<char>(N));
    visited.resize(M, vector<bool>(N, false));

    for (int i = 0; i < M; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++)
        {
            board[i][j] = str[j];
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j]) continue;

            Bfs(i, j);
        }
    }

    cout << white << " " << blue;

    return 0;
} 