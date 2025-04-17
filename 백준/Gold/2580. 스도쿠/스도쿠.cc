#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
vector<vector<int>> board(9, vector<int>(9));
vector<pair<int, int>> blanks;
bool isend = false;
int L;

void PrintBoard()
{
    for (auto& row : board)
    {
        for (auto& cell : row)
        {
            cout << cell << " ";
        }
        cout << "\n";
    }
}

bool Check(int y, int x, int num)
{
    //가로, 세로
    for (int i = 0; i < 9; i++)
    {
        if (board[y][i] == num) return false;
        if (board[i][x] == num) return false;
    }

    //네모
    int rectY = y / 3 * 3;
    int rectX = x / 3 * 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[rectY + i][rectX + j] == num) return false;
        }
    }

    return true;
}

void DFS(int cur) 
{
    if (isend == true) return;

    if (cur == L) 
    {
        PrintBoard();
        isend = true;
    }
    else
    {
        auto [ny, nx] = blanks[cur];

        for (int i = 1; i <= 9; i++) 
        {
            if (Check(ny, nx, i))
            {
                board[ny][nx] = i;
                DFS(cur + 1);
                board[ny][nx] = 0;
            }
        }
    }
}

int main() 
{
    INPUT_OPTIMIZE;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 0)
            {
                blanks.push_back({ i,j });
            }
        }
    }

    L = blanks.size();
    DFS(0);

    return 0;
} 