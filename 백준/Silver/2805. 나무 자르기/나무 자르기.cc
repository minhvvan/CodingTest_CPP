#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
long long N, M;
vector<long long> trees;

bool Check(long long h)
{
    long long result = 0;
    for (auto& tree : trees)
    {
        result += tree - h > 0 ? tree - h : 0;
    }

    return result >= M;
}

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N >> M;
    
    trees.resize(N);

    long long left = 0;
    long long right = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> trees[i];
        right = max(right, trees[i]);
    }

    long long ans = 0;
    while (left <= right)
    {
        long long mid = (left + right) / 2;

        if (Check(mid))
        {
            ans = max(ans, mid);
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;
}