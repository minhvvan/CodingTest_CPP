#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;

int prime[] = { 2, 3, 5, 7 };

bool IsPrime(int x)
{
    if (x == 1) return false;

    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0) return false;
    }

    return true;
}

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N;

    int target = pow(10, N - 1);
    int limit = pow(10, N);

    queue<int> q;
    vector<int> answers;
    for (int i = 0; i < 4; i++)
    {
        q.push(prime[i]);
    }

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        if (current >= target && current < limit)
        {
            answers.push_back(current);
            continue;
        }

        for (int i = 0; i <= 9; i++)
        {
            int num = current * 10 + i;
            if (IsPrime(num))
            {
                q.push(num);
            }
        }
    }

    for (auto& ans : answers)
    {
        cout << ans << "\n";
    }
   
    return 0;
} 