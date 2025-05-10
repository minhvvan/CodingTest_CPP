#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<bool> visited;

void Dfs(vector<int>& per, int depth)
{
    if (per.size() == N)
    {
        for (auto& num : per)
        {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (visited[i]) continue;

        per.push_back(i);
        visited[i] = true;

        Dfs(per, i + 1);
        per.pop_back();
        visited[i] = false;
    }
}

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N;

    visited.resize(N + 1, false);

    vector<int> temp;
    Dfs(temp, 1);
   

    return 0;
} 