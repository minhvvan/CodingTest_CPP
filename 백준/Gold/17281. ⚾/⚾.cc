#include <bits/stdc++.h>

using namespace std;

int N;

vector<vector<int>> hits;

void makePer(vector<vector<int>>& out, vector<int>& temp, vector<bool>& checked)
{
    if (temp.size() == 9)
    {
        out.push_back(temp);
        return;
    }

    if (temp.size() == 3)
    {
        temp.push_back(0);
        makePer(out, temp, checked);
        temp.pop_back();
    }
    else
    {
        for (int i = 1; i < 9; i++)
        {
            if (checked[i]) continue;

            temp.push_back(i);
            checked[i] = true;

            makePer(out, temp, checked);

            temp.pop_back();
            checked[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);
    
    cin >> N;

    hits.resize(N, vector<int>(9));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> hits[i][j];
        }
    }

    vector<vector<int>> Per;
    vector<int> temp;
    vector<bool> checked(9, false);
    
    makePer(Per, temp, checked);

    int ans = 0;
    for (auto& order : Per)
    {
        int score = 0;
        int idx = 0;
        for (int t = 0; t < N; t++)
        {
            int out = 0;
            vector<bool> base(4, false);
            while (out < 3)
            {
                int hit = hits[t][order[idx]];
                idx = (idx + 1) % 9;
                if (hit == 0)
                {
                    out++;
                    continue;
                }

                //주자 
                for (int i = 3; i > 0; i--)
                {
                    if (!base[i]) continue;

                    int newIdx = i + hit;
                    if (newIdx > 3) score++;
                    else base[newIdx] = true;
                    
                    base[i] = false;
                }

                //타자
                if (hit == 4) score++;
                else base[hit] = true;
            }
        }

        ans = max(ans, score);
    }

    cout << ans;
    
    return 0;
}