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

int A, B, C;
int Sum = 0;

const int MAX = 500 * 3 + 1;

int BFS()
{
    vector<vector<bool>> visited(MAX, vector<bool>(MAX, false));
    queue<pair<int, int>> q;
    q.push({ A,B });
    visited[A][B] = true;

    while (!q.empty())
    {
        auto [a, b] = q.front();
        q.pop();

        vector<int> current = { a, b, Sum - (a + b) };

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (current[i] < current[j])
                {
                    current[j] -= current[i];
                    current[i] *= 2;

                    if (visited[current[i]][current[j]]) continue;
                    visited[current[i]][current[j]] = true;
                    q.push({ current[i], current[j] });
                }
            }
        }
    }

    return visited[Sum / 3][Sum / 3];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B >> C;
    Sum = A + B + C;
    if (Sum % 3 != 0)
    {
        cout << 0;
        return 0;
    }

    cout << BFS();

    return 0;
}