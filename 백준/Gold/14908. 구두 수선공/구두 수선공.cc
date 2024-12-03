#include <bits/stdc++.h>

using namespace std;

struct Task
{
    Task(int n, double c) : num(n), cost(c)
    {};

    int num;
    double cost;

    bool operator < (const Task& Other) const
    {
        if (cost == Other.cost) return num < Other.num;
        return cost < Other.cost;
    }
};

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N;
    vector<Task> tasks;

    int size = 0;
    for (int i = 1; i <= N; i++)
    {
        double t, s;
        cin >> t >> s;
        tasks.push_back({ i, t/s });
    }

    sort(tasks.begin(), tasks.end());

    for (auto task : tasks)
    {
        cout << task.num << " ";
    }

    return 0;
}