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

int N, K;
vector<int> Kits;

int Exercise(vector<int>& temp, vector<bool>& visited)
{
    if (temp.size() == N)
    {
        int weight = 500;
        for (int i = 0; i < N; i++)
        {
            int w = Kits[temp[i]];

            weight -= K;
            weight += w;

            if (weight < 500) return 0;
        }

        return 1;
    }

    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        if (visited[i]) continue;

        visited[i] = true;
        temp.push_back(i);

        answer += Exercise(temp, visited);

        visited[i] = false;
        temp.pop_back();
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        Kits.push_back(temp);
    }

    vector<int> temp;
    vector<bool> visited(N, false);

    cout << Exercise(temp, visited);

	return 0;
}