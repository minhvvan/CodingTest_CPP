#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> lights;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N;
    lights.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> lights[i];
    }

    deque<vector<int>> groups;
    vector<int> temp;
    temp.push_back(N-1);
    for (int i = N - 2; i >= 0; i--)
    {
        if (lights[i] != lights[i + 1]) temp.push_back(i);
        else
        {
            groups.push_back(temp);
            temp.clear();
            temp.push_back(i);
        }
    }

    groups.push_back(temp);

    int ans = 0;
    for (int i = 0; i < groups.size(); i++)
    {
        int cnt = groups[i].size();
        if (i != 0) cnt += groups[i - 1].size();
        if (i != groups.size()-1) cnt += groups[i + 1].size();

        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}