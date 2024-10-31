#include <bits/stdc++.h>

using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);  

    cin >> N >> M;

    vector<int> materials(N);
    for (int i = 0; i < N; i++)
    {
        cin >> materials[i];
    }

    sort(materials.begin(), materials.end());

    int left = 0;
    int right = N-1;
    int ans = 0;

    while (left < right)
    {
        int weight = materials[left] + materials[right];

        if (weight == M)
        {
            ans++;
            left++;
        }
        else if (weight < M)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << ans;

    return 0;
}