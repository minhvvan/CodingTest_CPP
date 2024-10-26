#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<vector<int>> adj;
vector<int> inDegree;
vector<int> result;

bool TSort()
{
    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (q.empty()) return false;

        int current = q.front();
        q.pop();

        result.push_back(current);

        for (auto next : adj[current])
        {
            inDegree[next]--;

            if (inDegree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(1);
    
    cin >> N >> M;
    cin.ignore();

    adj.resize(N + 1);
    inDegree.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int K;
        cin >> K;

        vector<int> singer(K);
        cin >> singer[0];

        for (int i = 1; i < K; i++)
        {
            cin >> singer[i];

            adj[singer[i - 1]].push_back(singer[i]);
            inDegree[singer[i]]++;
        }
    }

    if (TSort())
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << "\n";
        }
    }
    else
    {
        cout << 0;
    }

    return 0;
}