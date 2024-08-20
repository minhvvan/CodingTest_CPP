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

string str;
int N;

struct Ball
{
    Ball(char c, int n) : color(c), num(n) {}
    char color;
    int num;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> str;

    int cnt = 1;
    char current = str[0];
    vector<Ball> balls;
    for (int i = 1; i < str.length(); i++)
    {
        if (current == str[i]) cnt++;
        else
        {
            Ball temp(current, cnt);
            balls.push_back(temp);
            cnt = 1;
            current = str[i];
        }
    }
    Ball temp(current, cnt);
    balls.push_back(temp);

    int ans = INT_MAX;
    //B가 왼쪽
    {
        int moveCnt = 0;
        for (auto& ball : balls)
        {
            if (ball.color == 'B') moveCnt += ball.num;
        }

        if (balls[0].color == 'B')
        {
            moveCnt -= balls[0].num;
        }

        ans = min(ans, moveCnt);
    }

    //R가 왼쪽
    {
        int moveCnt = 0;
        for (auto& ball : balls)
        {
            if (ball.color == 'R') moveCnt += ball.num;
        }

        if (balls[0].color == 'R')
        {
            moveCnt -= balls[0].num;
        }

        ans = min(ans, moveCnt);
    }

    //B가 오른쪽
    {
        int moveCnt = 0;
        for (auto itr = balls.rbegin(); itr != balls.rend(); itr++)
        {
            if (itr->color == 'B') moveCnt += itr->num;
        }

        if (balls.back().color == 'B')
        {
            moveCnt -= balls.back().num;
        }

        ans = min(ans, moveCnt);
    }

    //R이 오른쪽
    {
        int moveCnt = 0;
        for (auto itr = balls.rbegin(); itr != balls.rend(); itr++)
        {
            if (itr->color == 'R') moveCnt += itr->num;
        }

        if (balls.back().color == 'R')
        {
            moveCnt -= balls.back().num;
        }

        ans = min(ans, moveCnt);
    }

    cout << ans;

    return 0;
}