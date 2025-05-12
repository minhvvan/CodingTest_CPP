#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<pair<int, int>> lectures;

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        lectures.push_back({ a, b });
    }

    sort(lectures.begin(), lectures.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(lectures[0].second);

    for (int i = 1; i < N; i++)
    {
        auto& [a, b] = lectures[i];
        if (pq.top() <= a)
        {
            //같은 강의실
            pq.pop();
        }

        pq.push(b);
    }

    cout << pq.size();

    return 0;
} 