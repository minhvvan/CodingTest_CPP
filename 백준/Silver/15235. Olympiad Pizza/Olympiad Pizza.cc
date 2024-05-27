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

int N;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<int> Pizzas(N);
    vector<int> Answer(N);

    for (int i = 0; i < N; i++)
    {
        cin >> Pizzas[i];
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++)
    {
        q.push({ i, Pizzas[i] });
    }


    int time = 0;
    while (!q.empty())
    {
        auto [idx, pizza] = q.front();
        q.pop();
        time++;

        pizza--;
        if (pizza == 0)
        {
            Answer[idx] = time;
            continue;
        }

        q.push({ idx, pizza });
    }

    for (auto a : Answer)
    {
        cout << a << " ";
    }
    

	return 0;
}