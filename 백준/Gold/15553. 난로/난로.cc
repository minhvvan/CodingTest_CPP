#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> friends;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N >> K;
    friends.resize(N);

    int start = INT_MAX, end = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> friends[i];
        start = min(start, friends[i]);
        end = max(end, friends[i]);
    }

    //K개의 그룹으로 나눠야 함 = K-1개의 space가 생김
    //그룹사이의 거리가 최소로 되어야 함 = 그룹간의 거리가 최대로 되어야 함
    //K-1개의 Space를 최대로
    //거리를 모두 세어서 큰 4개를 고르고 그 4개를 기준으로 그룹을 나눔
    //그룹의 최대 - 최소 를 모두 더하면 답

    vector<tuple<int, int, int>> gaps;
    int ans = end - start + 1;
    for (int i = 1; i < N; i++)
    {
        int gap = friends[i] - friends[i - 1] - 1;
        gaps.push_back({ gap, i - 1, i });
    }

    sort(gaps.begin(), gaps.end(), greater());

    for (int i = 0; i < K-1; i++)
    {
        auto [gap, currentStart, curresntEnd] = gaps[i];
        ans -= gap;
    }

    cout << ans;

    return 0;
}