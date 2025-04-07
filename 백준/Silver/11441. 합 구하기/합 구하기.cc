#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M;
vector<int> sum;

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N;
    
    sum.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        int n;
        cin >> n;

        sum[i] = sum[i - 1] + n;
    }

    cin >> M;

    while (M--)
    {
        int s, e;
        cin >> s >> e;

        cout << sum[e] - sum[s - 1] << "\n";
    }

    return 0;
}