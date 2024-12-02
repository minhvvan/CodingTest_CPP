#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N;

    vector<int> opers(N);
    deque<int> origin;

    for (int i = 0; i < N; i++)
    {
        cin >> opers[i];
    }

    int num = 1;
    for (int i = N-1; i >= 0; i--)
    {
        if (opers[i] == 1)
        {
            origin.push_front(num);
        }
        else if (opers[i] == 2)
        {
            int top = origin.front();
            origin.pop_front();
            origin.push_front(num);
            origin.push_front(top);
        }
        else
        {
            origin.push_back(num);
        }

        num++;
    }

    for (auto num : origin)
    {
        cout << num << " ";
    }

    return 0;
}