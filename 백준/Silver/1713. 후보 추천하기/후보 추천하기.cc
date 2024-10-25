#include <bits/stdc++.h>

using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(1);
    
    cin >> N >> M;

    vector<int> votes(101, 0);
    vector<int> candidate;

    for (int i = 0; i < M; i++)
    {
        int current;
        cin >> current;

        bool flag = false;
        for (int j = 0; j < candidate.size(); j++)
        {
            if (candidate[j] == current)
            {
                votes[current]++;
                flag = true;
                break;
            }
        }

        if (flag) continue;

        if (candidate.size() < N)
        {
            candidate.push_back(current);
        }
        else
        {
            int minVote = INT_MAX;
            int minIdx = -1;
            for (int j = 0; j < candidate.size(); j++)
            {
                if (votes[candidate[j]] < minVote)
                {
                    minVote = votes[candidate[j]];
                    minIdx = candidate[j];
                }
            }

            candidate.erase(remove(candidate.begin(), candidate.end(), minIdx));
            votes[minIdx] = 0;

            candidate.push_back(current);
        }

        votes[current]++;
    }

    sort(candidate.begin(), candidate.end());

    for (auto c : candidate)
    {
        cout << c << " ";
    }

    return 0;
}