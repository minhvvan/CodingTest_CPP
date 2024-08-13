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
#include <bitset>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;

        if (input == 0)
        {
            if (pq.empty())
            {
                cout << 0 << "\n";
                continue;
            }

            cout << pq.top() << "\n";
            pq.pop();
        }
        else
        {
            pq.push(input);
        }
    }

    return 0;
}