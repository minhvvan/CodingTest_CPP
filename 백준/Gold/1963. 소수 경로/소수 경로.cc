#include <bits/stdc++.h>

using namespace std;

int T;
string currentPwd, nextPwd;
const int MAX = 10'000;
vector<bool> isPrime(MAX, true);

bool CheckPrime(string pwd)
{
    int num = 0;

    for (int i = 0; i < 4; i++)
    {
        num *= 10;
        num += pwd[i] - '0';
    }

    return isPrime[num] && 999 < num;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;

    cin >> T;

    for (int i = 2; i * i < MAX; i++)
    {
        if (isPrime[i]) 
        {
            for (int k = i * i; k < MAX; k += i) 
            {
                isPrime[k] = false;
            }
        }
    }

    while (T--)
    {
        cin >> currentPwd >> nextPwd;

        if (currentPwd == nextPwd)
        {
            cout << 0 << "\n";
            continue;
        }

        queue<string> q;
        q.push(currentPwd);

        bool bFind = false;
        set<string> visited;

        int depth = 0;
        while (!q.empty())
        {
            int size = q.size();

            for (int k = 0; k < size; k++)
            {
                auto current = q.front();
                q.pop();

                if (visited.count(current)) continue;
                visited.insert(current);

                //i번째 자리를 j로 바꿈
                for (int i = 0; i < 4; i++)
                {
                    if (bFind) break;
                    for (int j = 0; j < 10; j++)
                    {
                        string next = current;
                        next[i] = j + '0';

                        if (next == nextPwd)
                        {
                            bFind = true;
                            break;
                        }

                        if (CheckPrime(next) && visited.count(next) == 0)
                        {
                            q.push(next);
                        }
                    }
                }
            }

            depth++;

            if (bFind)
            {
                cout << depth << "\n";
                break;
            }
        }

        if (!bFind) cout << "Impossible\n";
    }

    return 0;
}