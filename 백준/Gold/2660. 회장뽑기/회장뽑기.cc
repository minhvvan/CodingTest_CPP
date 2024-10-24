#include <bits/stdc++.h>

using namespace std;

int N;
const int MAX = 987654321;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N;

    vector<vector<int>> dist(N + 1, vector<int>(N + 1, MAX));

    while (true)
    {
        int a, b;
        cin >> a >> b;

        if (a == -1 && b == -1) break;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        dist[i][i] = 0;
    }

    int minScore = MAX;
    vector<int> scores(N + 1);
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            int score = 0;
            for (int j = 1; j <= N; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[j][k]);
                score = max(score, dist[i][j]);
            }
            
            minScore = min(minScore, score);
            scores[i] = score;
        }
    }

    vector<int> candidate;
    for (int i = 1; i <= N; i++)
    {
        if (scores[i] == minScore)
        {
            candidate.push_back(i);
        }
    }

    cout << minScore << " " << candidate.size() << "\n";
    for(auto p : candidate)
    {
        cout << p << " ";
    }

    return 0;
}