#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <climits>
#include <queue>
#include <map>
#include <set>

using namespace std;

void PostOrder(int start, int end, int idx, vector<int>& PreOrder, vector<int>& InOrder)
{
    for (int i = start; i < end; i++)
    {
        if (PreOrder[idx] == InOrder[i])
        {
            PostOrder(start, i, idx + 1, PreOrder, InOrder);
            PostOrder(i+1, end, idx + 1 + i - start, PreOrder, InOrder);
            cout << PreOrder[idx] << " ";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    cin >> T;

    while (T-- > 0)
    {
        cin >> N;

        vector<int> PreOrder(N);
        vector<int> InOrder(N);

        for (int i = 0; i < N; i++)
        {
            cin >> PreOrder[i];
        }

        for (int i = 0; i < N; i++)
        {
            cin >> InOrder[i];
        }

        PostOrder(0, N, 0, PreOrder, InOrder);
        cout << "\n";
    }

    return 0;
}