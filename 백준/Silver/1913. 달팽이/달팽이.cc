#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M;
vector<vector<int>> board;

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

void Print()
{
    for (auto row : board)
    {
        for (auto cell : row)
        {
            cout << cell << " ";
        }

        cout << "\n";
    }
}

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N >> M;

    board.resize(N, vector<int>(N));

    int y = N / 2;
    int x = N / 2;

    int num = 1;
    int dir = 0;

    int moveCnt = 0;
    int depth = 1;

    int ansY = 0;
    int ansX = 0;

    while(num <= N * N)
    {
        for (int i = 0; i < depth; i++)
        {
            if (num == M) 
            {
                ansY = y + 1;
                ansX = x + 1;
            }
            board[y][x] = num++;

            y = y + dy[dir];
            x = x + dx[dir];
        }

        dir = (dir + 1) % 4;

        moveCnt++;
        if (moveCnt == 2) 
        {
            depth++;
            moveCnt = 0;
        }
    }

    Print();
    cout << ansY << " " << ansX;

    return 0;
} 