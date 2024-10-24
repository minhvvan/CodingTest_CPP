#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> board(20, vector<int>(20));
vector<vector<int>> visited(20, vector<int>(20, 0));

vector<int> dy = { -1, -1, 0, 1, 1, 1, 0, -1 };
vector<int> dx = { 0, 1, 1, 1, 0, -1, -1, -1 };

bool findFive(int i, int j, int dir)
{
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({ i,j });

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        if (visited[y][x] & (1 << dir)) break;
        if (board[i][j] != board[y][x]) break;
        
        visited[y][x] += (1 << dir);
        cnt++;

        y += dy[dir];
        x += dx[dir];

        if (y < 0 || y > 19 || x < 0 || x > 19) break;
        q.push({ y,x });
    }

    return cnt == 5;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);
    
    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (board[i][j] == 0) continue;
                if (visited[i][j] & (1 << k)) continue;

                if (findFive(i, j, k))
                {
                    vector<pair<int, int>> temp;
                    temp.push_back({ j,i });
                    int y = i;
                    int x = j;
                    for (int t = 0; t < 4; t++)
                    {
                        y += dy[k];
                        x += dx[k];
                        temp.push_back({ x,y });
                    }

                    sort(temp.begin(), temp.end());

                    cout << board[i][j] << "\n";
                    cout << temp[0].second << " " << temp[0].first;
                    return 0;
                }
            }
        }
    }

    cout << 0;

    return 0;
}