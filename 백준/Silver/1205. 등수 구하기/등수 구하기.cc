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

int N, S, P;
const int MAX = 2'000'000'001;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S >> P;

    if (N == 0)
    {
        cout << 1;
        return 0;
    }

    int minScore = MAX;
    int maxScore = 0;
    vector<int> Scores(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> Scores[i];
    }

    int cnt = 0;
    int ans = 1;
    for (int i = 0; i < N; i++) 
    {
        if (S < Scores[i]) ans++;
        else if(S > Scores[i]) break;

        cnt++;
    }


    if (cnt == P) ans = -1;
    if (N == 0) ans = 1;

    cout << ans;

    return 0;
}