#include <stdio.h>
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

string N;
int K, M;

int Convert(string s)
{
    int num = 0;
    for (int i = 0; i < s.size(); i++)
    {
        num *= 10;
        num += s[i] - '0';
    }

    return num;
}

int BFS()
{
    queue<string> q;
    q.push(N);
    int tryNum = 0;
    int ans = -1;


    while (!q.empty() && tryNum++ <= K)
    {
        set<string> checked;
        int size = q.size();
        for (int t = 0; t < size; t++)
        {
            string current = q.front();
            q.pop();

            for (int i = 0; i < M-1; i++)
            {
                for (int j = i + 1; j < M; j++)
                {
                    if (i == 0 && current[j] == '0')continue;
                    string copied = current;
                    swap(copied[i], copied[j]);

                    if (checked.find(copied) != checked.end()) continue;

                    if (tryNum == K)
                    {
                        ans = max(ans, Convert(copied));
                        continue;
                    }

                    q.push(copied);
                    checked.insert(copied);
                }
            }
        }
    }

    if (tryNum != K) return -1;
    else return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    M = N.size();

    cout << BFS();
 
    return 0;
}