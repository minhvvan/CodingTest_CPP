#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int M, N;

struct Num
{
    set<int> light;
    set<int> heavy;
};

vector<Num> nums;
vector<bool> visitedLight;
vector<bool> visitedHeavy;

void Dfslight(set<int>& light, int idx)
{
    if (nums[idx].light.size() == 0)
    {
        visitedLight[idx] = true;
        return;
    }

    for (auto itr = nums[idx].light.begin(); itr != nums[idx].light.end(); itr++)
    {
        if (!visitedLight[*itr])
        {
            visitedLight[*itr] = true;
            Dfslight(nums[*itr].light, *itr);
        }

        for (auto& node : nums[*itr].light)
        {
            light.insert(node);
        }
    }
}

void Dfsheavy(set<int>& heavy, int idx)
{
    if (nums[idx].heavy.size() == 0)
    {
        visitedHeavy[idx] = true;
        return;
    }

    for (auto itr = nums[idx].heavy.begin(); itr != nums[idx].heavy.end(); itr++)
    {
        if (!visitedHeavy[*itr])
        {
            visitedHeavy[*itr] = true;
            Dfsheavy(nums[*itr].heavy, *itr);
        }

        for(auto& node : nums[*itr].heavy)
        {
            heavy.insert(node);
        }
    }

}

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N >> M;

    nums.resize(N + 1);
    visitedLight.resize(N + 1);
    visitedHeavy.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        nums[a].light.insert(b);
        nums[b].heavy.insert(a);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        auto num = nums[i];

        //가벼운거 업데이트
        Dfslight(num.light, i);

        //무거운거 업데이트
        Dfsheavy(num.heavy, i);

        bool bPossible = true;
        if (num.light.size() > N / 2) bPossible = false;
        if (num.heavy.size() > N / 2) bPossible = false;

        if (!bPossible)
        {
            ans++;
        }
    }

    cout << ans;

    return 0;
} 