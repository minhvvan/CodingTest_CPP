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

int N, M, R, C;

enum DIR
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class Robot
{
public:
    int dir;
    pair<int, int> pos;
};

vector<int> dy = { 1, 0, -1, 0 };
vector<int> dx = { 0, 1, 0, -1 };


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> C >> R >> N >> M;

    vector<Robot*> Robots;

    for (int i = 0; i < N; i++)
    {
        int y, x;
        char dir;
        cin >> x >> y >> dir;

        int d = 0;
        switch (dir)
        {
        case 'N':
            d = NORTH;
            break;
        case 'E':
            d = EAST;
            break;
        case 'S':
            d = SOUTH;
            break;
        case 'W':
            d = WEST;
            break;
        }

        Robot* bot = new Robot();
        bot->pos = { y, x };
        bot->dir = d;

        Robots.push_back(bot);
    }

    for (int i = 0; i < M; i++)
    {
        int idx, num;
        char oper;

        cin >> idx >> oper >> num;
        auto& robot = Robots[idx - 1];

        for (int t = 0; t < num; t++)
        {
            switch (oper)
            {
            case 'L':
                robot->dir = (robot->dir - 1 + 4) % 4;
                break;
            case 'R':
                robot->dir = (robot->dir + 1) % 4;
                break;
            case 'F':
                robot->pos.first += dy[robot->dir];
                robot->pos.second += dx[robot->dir];
                break;
            }

            if (robot->pos.first <= 0 || robot->pos.first > R || robot->pos.second <= 0 || robot->pos.second > C)
            {
                cout << "Robot " << idx << " crashes into the wall";
                return 0;
            }

            for (int j = 0; j < N; j++)
            {
                if (idx-1 == j) continue;
                if (Robots[j]->pos.first == robot->pos.first && Robots[j]->pos.second == robot->pos.second)
                {
                    cout << "Robot " << idx << " crashes into robot " << j+1;
                    return 0;
                }
            }
        }
    }

    cout << "OK";

	return 0;
}