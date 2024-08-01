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

int T, N;
const int MAX = 6'000;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> N;

        vector<int> ranks(N);
        map<int, vector<int>> teamCnt;
        map<int, vector<int>> teamScore;
        for (int i = 0; i < N; i++)
        {
            cin >> ranks[i];
            teamCnt[ranks[i]].push_back(i);
        }

        int s = 1;
        for (auto rank : ranks)
        {
            if (teamCnt[rank].size() != 6) continue;
            teamScore[rank].push_back(s++);
        }

        int ans = 0;
        int minScore = MAX;
        for (auto [team, scores] : teamScore)
        {
            int score = 0;
            for (int i = 0; i < 4; i++)
            {
                score += scores[i];
            }

            if (minScore == score)
            {
                if (teamScore[ans][4] > scores[4])
                {
                    ans = team;
                }
            }
            else if (minScore > score)
            {
                ans = team;
                minScore = score;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}