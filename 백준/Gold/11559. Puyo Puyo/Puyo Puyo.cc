#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> board(12, vector<char>(6));

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

void Print()
{
    for (auto row : board)
    {
        for (auto cell : row)
        {
            cout << cell;
        }
        cout << "\n";
    }
    cout << "\n";
}

void BFS(vector<vector<bool>>& checked, vector<vector<bool>>& visited, int i, int j)
{
    //R은 빨강, G는 초록, B는 파랑, P는 보라, Y는 노랑
    char color = board[i][j];

    queue<pair<int, int>> q;
    visited[i][j] = true;
    q.push({ i,j });

    vector<pair<int, int>> sameColors;
    sameColors.push_back({ i,j });
    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newY = y + dy[i];
            int newX = x + dx[i];

            if (newY < 0 || newY >= 12 || newX < 0 || newX >= 6) continue;
            if (visited[newY][newX]) continue;
            if (board[newY][newX] != color) continue;

            visited[newY][newX] = true;
            q.push({ newY, newX });
            sameColors.push_back({ newY,newX });
        }
    }

    if (sameColors.size() >= 4)
    {
        for (auto [y, x] : sameColors)
        {
            checked[y][x] = true;
        }
    }

    return;
}

void Down()
{
    for (int j = 0; j < 6; j++)
    {
        int bottomIdx = 11;
        for (int i = 11; i >= 0; i--)
        {
            if (board[i][j] == '.')
            {
                bottomIdx = max(bottomIdx, i);
            }
            else
            {
                if (bottomIdx != i)
                {
                    board[bottomIdx][j] = board[i][j];
                    board[i][j] = '.';
                }

                bottomIdx--;
            }
        }
    }
}

bool Pop()
{
    bool bPop = false;
    vector<vector<bool>> checked(12, vector<bool>(6, false));
    vector<vector<bool>> visited(12, vector<bool>(6, false));

    for (int i = 11; i >= 0; i--)
    {
        for (int j = 5; j >= 0; j--)
        {
            if (board[i][j] == '.') continue;
            if (checked[i][j]) continue;
            if (visited[i][j]) continue;

            BFS(checked, visited, i, j);
        }
    }

    for (int i = 11; i >= 0; i--)
    {
        for (int j = 5; j >= 0; j--)
        {
            if (checked[i][j])
            {
                board[i][j] = '.';
                bPop = true;
            }
        }
    }

    Down();

    return bPop;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);
    
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    while (Pop())
    {
        ans++;
    }

    cout << ans;

    return 0;
}