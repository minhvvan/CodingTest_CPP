#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <climits>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

int N, K;
string Table;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    cin >> Table;
	
    vector<bool> ate(N, false);
    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        if (Table[i] == 'H') continue;

        for (int j = i - K; j <= i + K; j++)
        {
            if (j < 0 || j >= N) continue;
            if (Table[j] == 'H' && !ate[j])
            {
                ate[j] = true;
                ans++;
                break;
            }
        }
    }

    cout << ans;
    return 0;
}