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
#include <list>
#include <bitset>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<int> Order(N);
    for (int i = 0; i < N; i++)
    {
        cin >> Order[i];
    }

    list<int> answer;
    answer.push_back(N - 1);

    for (int i = N - 2; i >= 0; i--)
    {
        int front = Order[i];
        int currentSize = answer.size();

        int diff = currentSize - front;

        auto itr = answer.rbegin();
        for (int j = 0 ; j < diff; j++) itr++;

        answer.insert(itr.base(), i);
    }

    for (auto ans : answer)
    {
        cout << ans + 1 << " ";
    }

    return 0;
}