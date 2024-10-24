#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> reverseDir = { 0, 3, 4, 1, 2 };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N;

    vector<int> specimen(N);
    vector<vector<int>> ans;

    for (int i = 0; i < N; i++)
    {
        cin >> specimen[i];
    }

    cin >> M;
    for (int t = 0; t < M; t++)
    {
        vector<int> temp;
        for (int j = 0; j < N; j++)
        {
            int a;
            cin >> a;
            temp.push_back(a);
        }

        //정방향
        bool bMatch = false;
        for (int i = 0; i < N; i++)
        {
            bool flag = true;
            for (int j = 0; j < N; j++)
            {
                if (specimen[j] != temp[(j + i) % N])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                bMatch = true;
                ans.push_back(temp);
                break;
            }
        }

        if (bMatch) continue;

        //역방향
        for (int i = 0; i < N; i++)
        {
            bool flag = true;
            for (int j = 0; j < N; j++)
            {
                if (specimen[N-1-j] != reverseDir[temp[(j + i) % N]])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                bMatch = true;
                ans.push_back(temp);
                break;
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto& per : ans)
    {
        for (auto& num : per)
        {
            cout << num << " ";
        }

        cout << "\n";
    }

    return 0;
}