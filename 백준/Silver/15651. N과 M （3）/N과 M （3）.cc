#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, M;

void MakeComb(vector<int>& temp)
{
    if (temp.size() == M)
    {
        for (auto num : temp)
        {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        temp.push_back(i);
        MakeComb(temp);
        temp.pop_back();
    }
}

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N >> M;

    vector<int> temp;
    MakeComb(temp);

    return 0;
}