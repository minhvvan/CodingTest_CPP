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

vector<int> dy = { 1, 1, 1, 0, 0, 0, -1, -1, -1 };
vector<int> dx = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

bool MoveToPlayer(pair<int, int>& Player, pair<int, int>& Robot)
{
    pair<int, int> result;
    int minDist = INT_MAX;

    //cout << "Robot: " << "{" << Robot.first << ", " << Robot.second << "} -> ";
    for (int i = 0; i < 9; i++)
    {
        if (i == 4) continue;
        int newY = Robot.first + dy[i];
        int newX = Robot.second + dx[i];

        int temp = abs(Player.first - newY) + abs(Player.second - newX);
        if (temp < minDist)
        {
            minDist = temp;
            result = { newY, newX };
        }
    }

    Robot = move(result);
    //cout << "{" << Robot.first << ", " << Robot.second << "}\n";
    return minDist == 0;
}

void Print(vector<vector<char>>& Board)
{
    for (auto row : Board)
    {
        for (auto c : row)
        {
            cout << c;
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int R, C;
    cin >> R >> C;

    vector<vector<char>> Board(R, vector<char>(C, '.'));

    pair<int, int> Player;
    vector<pair<int, int>> Robots;
    string Command;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            char temp;
            cin >> temp;

            if (temp == 'I') Player = { i,j };
            else if (temp == 'R') Robots.push_back({ i,j });
        }
    }

    cin >> Command;

    for (int t = 0; t < Command.size(); t++)
    {
        int dir = (Command[t] - '0') - 1;

        //move player
        //cout << "Player: " << "{" << Player.first << ", " << Player.second << "} -> ";
        Player.first += dy[dir];
        Player.second += dx[dir];

        for (auto& r : Robots)
        {
            if (Player == r)
            {
                cout << "kraj " << t + 1;
                return 0;
            }
        }

        //cout << "{" << Player.first << ", " << Player.second << "}\n";


        //move robots
        map<pair<int, int>, vector<int>> robotPos;
        for (int i = 0 ; i < Robots.size(); i++)
        {
            if (MoveToPlayer(Player, Robots[i]))
            {
                cout << "kraj " << t + 1;
                return 0;
            }
            robotPos[Robots[i]].push_back(i);
        }

        vector<pair<int, int>> robotTemp;
        for (auto itr = robotPos.begin(); itr != robotPos.end(); itr++)
        {
            if (itr->second.size() <= 1)
            {
                robotTemp.push_back(itr->first);
            }
            else
            {
                Board[itr->first.first][itr->first.second] = '.';
            }
        }

        Robots = move(robotTemp);
    }

    Board[Player.first][Player.second] = 'I';
    for (auto& robot : Robots)
    {
        Board[robot.first][robot.second] = 'R';
    }

    Print(Board);

	return 0;
}