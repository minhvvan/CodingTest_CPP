#include <bits/stdc++.h>

using namespace std;

int N, C, M;

struct Box
{
    Box(int s, int e, int a) : start(s), end(e), amount(a) {};
    int start, end, amount;

    bool operator < (const Box& other)
    {
        return end < other.end;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N >> C >> M;

    vector<Box> Boxes;
    vector<int> truck(N);

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Boxes.push_back({ a,b,c });
    }

    sort(Boxes.begin(), Boxes.end());

    vector<Box> current;
    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        auto& [start, end, amount] = Boxes[i];

        int temp = 0;
        int cnt = 0;

        for (int j = start; j < end; j++) 
        {
            temp = max(temp, truck[j]); 
        }

        cnt = min(C - temp, amount);

        for (int j = start; j < end; j++) 
        {
            truck[j] += cnt;
        }

        ans += cnt;
    }

    cout << ans;

    return 0;
}