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
#include <bitset>

using namespace std;

int p, l, m;
string n;

bool cmp(const pair<int, string>& a, const pair<int, string>& b)
{
    return a.second < b.second;
}

struct Room
{
    Room(int level, string nickname)
    {
        minLevel = level - 10;
        maxLevel = level + 10;

        players.push_back({ level, nickname });
    }

    int minLevel;
    int maxLevel;

    vector<pair<int, string>> players;

    bool Enter(int level, string nickname)
    {
        if (level < minLevel || level > maxLevel) return false;
        if (players.size() == m) return false;

        players.push_back({ level, nickname });
        return true;
    }

    void print()
    {
        if (players.size() == m) cout << "Started!\n";
        else cout << "Waiting!\n";

        sort(players.begin(), players.end(), cmp);

        for (auto [level, nickname] : players)
        {
            cout << level << " " << nickname << "\n";
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> p >> m;

    vector<Room> rooms;
    for (int i = 0; i < p; i++)
    {
        cin >> l >> n;

        bool bEnter = false;
        for (auto& room : rooms)
        {
            bEnter = room.Enter(l, n);
            if (bEnter) break;
        }

        if (!bEnter)
        {
            Room newRoom(l, n);
            rooms.push_back(newRoom);
        }
    }

    for (auto room : rooms)
    {
        room.print();
    }

    return 0;
}