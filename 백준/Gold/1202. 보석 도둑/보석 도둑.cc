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
#include <unordered_set>
#include <set>
#include <list>
#include <bitset>

using namespace std;

int N, K;
vector<pair<int,int>> jewels;
vector<int> backpacks;
priority_queue<int> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N >> K;
    backpacks.resize(K);

    for (int i = 0; i < N; i++)
    {
        int m, v;
        cin >> m >> v;
        jewels.push_back({ m,v });
    }

    for (int i = 0; i < K; i++)
    {
        cin >> backpacks[i];
    }

    sort(jewels.begin(), jewels.end());
    sort(backpacks.begin(), backpacks.end());

    int idx = 0;
    long long sum = 0;

    for (int i = 0; i < K; i++) 
    {
        while (idx < N && jewels[idx].first <= backpacks[i])
        {
            pq.push(jewels[idx].second);
            idx++;
        }

        if (!pq.empty()) 
        {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum;

    return 0;
}