#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, L;
vector<int> blanks;

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N >> L;

    blanks.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> blanks[i];
    }

    sort(blanks.begin(), blanks.end());

    int ans = 0;
    int right = 0;
    for (int i = 0; i < N; i++)
    {
        if (blanks[i] > right)
        {
            ans++;
            right = blanks[i] + L - 1;
        }
    }

    cout << ans;

    return 0;
} 