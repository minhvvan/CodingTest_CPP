#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<pair<int, int>> eggs;
int ans = 0;

void Dfs(int current, int broken)
{
    if (current == N)
    {
        ans = max(broken, ans);
        return;
    }

    bool hit = false;

    //이미 깨진 계란은 다음 계란으로
    if (eggs[current].first <= 0)
    {
        Dfs(current + 1, broken);
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (i == current) continue;
            if (eggs[i].first <= 0) continue;

            hit = true;

            //current계란으로 i번 계란을 친다.
            eggs[i].first -= eggs[current].second;
            eggs[current].first -= eggs[i].second;

            if (eggs[i].first <= 0) broken++;
            if (eggs[current].first <= 0) broken++;

            Dfs(current + 1, broken);

            if (eggs[i].first <= 0) broken--;
            if (eggs[current].first <= 0) broken--;

            eggs[i].first += eggs[current].second;
            eggs[current].first += eggs[i].second;
        }
    }

    if (current != N && !hit)
    {
        Dfs(current + 1, broken);
    }
}

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int s, w;
        cin >> s >> w;

        eggs.push_back({ s, w });
    }

    Dfs(0, 0);

    cout << ans;

    return 0;
} 