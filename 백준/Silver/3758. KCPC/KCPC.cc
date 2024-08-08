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

int T;
int n, k, t, m;

struct TeamScore
{
    TeamScore(int id):
        teamID(id)
    {
        scores.assign(k, 0);
    }

    int teamID;
    vector<int> scores;
    int totalScore = 0;
    int lastSubmitTime = 0;
    int submitCount = 0;

    void UpdateScore(int testNum, int score, int time)
    {
        submitCount++;
        lastSubmitTime = time;
        if (scores[testNum] < score)
        {
            totalScore += score - scores[testNum];
            scores[testNum] = score;
        }
    }

    bool operator <(const TeamScore& Other)
    {
        if (totalScore != Other.totalScore) return totalScore > Other.totalScore;
        if (submitCount != Other.submitCount) return submitCount < Other.submitCount;
        return lastSubmitTime < Other.lastSubmitTime;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> n >> k >> t >> m;

        vector<TeamScore> Teams;
        for (int i = 0; i < n; i++)
        {
            Teams.push_back(TeamScore(i));
        }

        for (int i = 0; i < m; i++)
        {
            int team, test, score;
            cin >> team >> test >> score;

            Teams[team-1].UpdateScore(test-1, score, i);
        }

        sort(Teams.begin(), Teams.end());

        for (int i = 0 ; i < n; i++)
        {
            if (Teams[i].teamID == t-1)
            {
                cout << i + 1 << "\n";
                break;
            }
        }
    }

    return 0;
}