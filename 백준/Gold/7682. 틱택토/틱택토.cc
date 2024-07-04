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

using namespace std;

int N;

bool checkX(vector<vector<int>>& Board)
{
    for (int i = 0; i < 3; i++)
    {
        //가로
        if (Board[i][0] == 'X')
        {
            if (Board[i][0] == Board[i][1] && Board[i][0] == Board[i][2]) return true;
        }

        //세로
        if (Board[0][i] == 'X')
        {
            if (Board[0][i] == Board[1][i] && Board[0][i] == Board[2][i]) return true;
        }
    }

    if (Board[0][0] == 'X' && Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2]) return true;
    if (Board[0][2] == 'X' && Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0]) return true;

    return false;
}

bool checkO(vector<vector<int>>& Board)
{
    for (int i = 0; i < 3; i++)
    {
        //가로
        if (Board[i][0] == 'O')
        {
            if (Board[i][0] == Board[i][1] && Board[i][0] == Board[i][2]) return true;
        }

        //세로
        if (Board[0][i] == 'O')
        {
            if (Board[0][i] == Board[1][i] && Board[0][i] == Board[2][i]) return true;
        }
    }

    if (Board[0][0] == 'O' && Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2]) return true;
    if (Board[0][2] == 'O' && Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0]) return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        string input;
        cin >> input;

        if (input == "end") break;

        vector<vector<int>> Board(3, vector<int>(3));

        int cntO = 0;
        int cntX = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                Board[i][j] = input[i * 3 + j];
                if (Board[i][j] == 'O') cntO++;
                if (Board[i][j] == 'X') cntX++;
            }
        }

        //X가 2번 놓거나 O가 2번 놓았을 때
        if (cntX < cntO || cntX > cntO + 1)
        {
            cout << "invalid" << "\n";
            continue;
        }

        bool XTik = checkX(Board);
        bool OTik = checkO(Board);

        if (XTik && !OTik && cntX == cntO + 1) cout << "valid\n"; // X가 이긴 경우
        else if (!XTik && OTik && cntX == cntO) cout << "valid\n"; // O가 이긴 경우
        else if (!XTik && !OTik && cntX == 5 && cntO == 4) cout << "valid\n"; // 가득 찬 경우
        else cout << "invalid\n";
    }


    return 0;
}