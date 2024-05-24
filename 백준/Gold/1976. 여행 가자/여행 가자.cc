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

int N, M;
vector<int> link;

int find(int node)
{
    if (node == link[node]) return node;
    return link[node] = find(link[node]); 
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a < b) link[b] = a;
    else link[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vector<vector<int>> Roads(N, vector<int>(N, 0));
    vector<int> Cities(M);

    for (int i = 0; i < N; i++)
    {
        link.push_back(i);

        for (int j = 0; j < N; j++)
        {
            cin >> Roads[i][j];
        }
    }

    for (int i = 0; i < M; i++)
    {
        int temp;
        cin >> temp;
        Cities[i] = temp-1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Roads[i][j] == 0) continue;
            unite(i, j);
        }
    }

    int currentCity = Cities[0];
    for (int i = 1; i < M; i++)
    {
        if (link[currentCity] != link[Cities[i]])
        {
            cout << "NO";
            return 0;
        }

        currentCity = Cities[i];
    }

    cout << "YES";

	return 0;
}