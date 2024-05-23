#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <climits>
#include <queue>
#include <map>
#include <set>

using namespace std;

int N, M;

vector<int> dy = { 1, -1, 0, 0 };
vector<int> dx = { 0, 0, 1, -1 };

enum Move
{
    DOWN,
    UP,
    RIGHT,
    LEFT
};

bool IsMovable(vector<vector<char>>& Space, int dir, pair<int,int>& CaptainPos)
{
    auto [newY, newX] = CaptainPos;

    while (true)
    {
        newY += dy[dir];
        newX += dx[dir];

        if (newY < 0 || newY >= N) return false;
        if (Space[newY][newX] == 'D')
        {
            CaptainPos = { newY, newX };
            return true;
        }
        if (Space[newY][newX] == '#') break;
    }

    newY -= dy[dir];
    newX -= dx[dir];

    CaptainPos = { newY, newX };

    return true;
}

bool IsInner(int y, int x)
{
    return (y >= 0 && y < N && x >= 0 && x < M);
}

int BFS(vector<vector<char>>& Space, pair<int, int>& CaptainPos)
{
    //switch, {y, x}
    deque<pair<int, pair<int,int>>> dq;
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    dq.push_back({ 0, CaptainPos });

    //cost: 홀수 -> UP, 짝수 -> DOWN
    while (!dq.empty())
    {
        auto [cost, pos] = dq.front();
        dq.pop_front();

        if (visited[pos.first][pos.second]) continue;
        visited[pos.first][pos.second] = true;
        int DIR = cost % 2;

        //cout << pos.first << "," << pos.second << "\n";

        //LEFT
        {
            int newY = pos.first + dy[LEFT];
            int newX = pos.second + dx[LEFT];

            //cost = 0 : front
            if (IsInner(newY, newX))
            {
                if (Space[newY][newX] == 'D') return cost;

                pair<int, int> newCaptainPos = { newY, newX };
                if (Space[newY][newX] == '.' && IsMovable(Space, DIR, newCaptainPos))
                {
                    if (Space[newCaptainPos.first][newCaptainPos.second] == 'D') return cost;
                    dq.push_front({ cost, newCaptainPos });
                }
            }
        }

        //RIGHT
        {
            int newY = pos.first + dy[RIGHT];
            int newX = pos.second + dx[RIGHT];

            //cost = 0 : front
            if (IsInner(newY, newX))
            {
                if (Space[newY][newX] == 'D') return cost;

                pair<int, int> newCaptainPos = { newY, newX };
                if (Space[newY][newX] == '.' && IsMovable(Space, DIR, newCaptainPos))
                {
                    if (Space[newCaptainPos.first][newCaptainPos.second] == 'D') return cost;
                    dq.push_front({ cost, newCaptainPos });
                }
            }
        }


        //DIR
        {
            int newDir = (DIR + 1) % 2;
            pair<int, int> newCaptainPos = { pos.first, pos.second };

            if (IsMovable(Space, newDir, newCaptainPos))
            {
                if (Space[newCaptainPos.first][newCaptainPos.second] == 'D') return cost+1;
                dq.push_back({ cost + 1, newCaptainPos });
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vector<vector<char>> Space(N, vector<char>(M, '.'));
    pair<int, int> CaptainPos;
    pair<int, int> DoctorPos;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Space[i][j];
            if (Space[i][j] == 'C') CaptainPos = { i,j };
            else if (Space[i][j] == 'D') DoctorPos = { i,j };
        }
    }

    if (!IsMovable(Space, DOWN, CaptainPos))
    {
        cout << -1;
        return 0;
    }

    cout << BFS(Space, CaptainPos);

	return 0;
}