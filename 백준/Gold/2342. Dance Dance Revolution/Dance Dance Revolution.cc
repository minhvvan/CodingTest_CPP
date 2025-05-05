#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;

vector<int> opers;
map<pair<int, int>, vector<int>> dp;
vector<int> idxMap;
const int MAX = 987654321;

vector<int> GetNear(int a)
{
    vector<int> result;

    if (a == 4)
    {
        result.push_back(1);
        result.push_back(3);
    }
    else if(a == 1)
    {
        result.push_back(2);
        result.push_back(4);
    }
    else
    {
        result.push_back(a + 1);
        result.push_back(a - 1);
    }

    return result;
}

int GetOpposite(int a)
{
    if (a == 1) return 3;
    if (a == 2) return 4;
    if (a == 3) return 1;
    if (a == 4) return 2;
}


int main() 
{
    INPUT_OPTIMIZE;

    opers.push_back(-1);

    while (true)
    {
        int d;
        cin >> d;

        if (d == 0) break;

        opers.push_back(d);
    }

    if (opers.size() == 1)
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            dp[{i, j}].resize(opers.size(), MAX);
        }
    }

    //초기화
    dp[{0, 0}][0] = 0;

    //중앙에서 옮기기
    dp[{0, opers[1]}][1] = 2;
    dp[{opers[1], 0}][1] = 2;

    for (int j = 1; j < opers.size(); j++)
    {
        for (auto& [foots, cost] : dp)
        {
            int l = foots.first;
            int r = foots.second;

            if (l == opers[j])
            {
                //같은 발
                dp[foots][j] = min(dp[foots][j], dp[{l, r}][j - 1] + 1);

                //왼발 옮기기
                {
                    //중앙에서 옮기기
                    dp[foots][j] = min(dp[foots][j], dp[{0, r}][j - 1] + 2);

                    //인접한 칸 옮기기(2개)
                    auto near = GetNear(l);
                    if (near[0] != r)
                    {
                        dp[foots][j] = min(dp[foots][j], dp[{near[0], r}][j - 1] + 3);
                    }
                    if (near[1] != r)
                    {
                        dp[foots][j] = min(dp[foots][j], dp[{near[1], r}][j - 1] + 3);
                    }

                    //반대 칸 옮기기
                    if (GetOpposite(l))
                    {
                        dp[foots][j] = min(dp[foots][j], dp[{GetOpposite(l), r}][j - 1] + 4);
                    }
                }
            }
            else if (r == opers[j])
            {
                //같은 발
                dp[foots][j] = min(dp[foots][j], dp[{l, r}][j - 1] + 1);

                //오른발 옮기기
                {
                    //중앙에서 옮기기
                    dp[foots][j] = min(dp[foots][j], dp[{l, 0}][j - 1] + 2);

                    //인접한 칸 옮기기(2개)
                    auto near = GetNear(r);
                    if (near[0] != l)
                    {
                        dp[foots][j] = min(dp[foots][j], dp[{l, near[0]}][j - 1] + 3);
                    }
                    if (near[1] != l)
                    {
                        dp[foots][j] = min(dp[foots][j], dp[{l, near[1]}][j - 1] + 3);
                    }

                    //반대 칸 옮기기
                    if (GetOpposite(r))
                    {
                        dp[foots][j] = min(dp[foots][j], dp[{l, GetOpposite(r)}][j - 1] + 4);
                    }
                }
            }
        }
    }

    int ans = INT_MAX;
    for (auto& [foots, cost] : dp)
    {
        if (foots.first == 0 && foots.second == 0) continue;
        ans = min(ans, cost[opers.size() - 1]);

        //cout << "{" << foots.first << "," << foots.second << "}: ";
        //for (auto c : cost)
        //{
        //    cout << c << " ";
        //}
        //cout << "\n";

    }

    cout << ans;

    return 0;
} 