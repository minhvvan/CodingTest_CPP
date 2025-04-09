#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<int> buildings;
vector<pair<int, int>> buildingStack;

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N;
    buildings.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> buildings[i];
    }

    /*
    * 오른쪽으로만 볼 수 있음
    * 자신보다 큰 수가 오기전까지 빌딩을 관찰 가능
    * lcs?
    * 10 3 7 4 12 2
    * i이후로 등장하는 자신보다 큰 빌딩까지의 거리
    */

    long long ans = 0;

    buildingStack.push_back({ buildings[0], 0 });
    for (int i = 1; i < N; i++)
    {
        while (!buildingStack.empty())
        {
            auto& [h, idx] = buildingStack.back();

            if (h > buildings[i]) break;

            buildingStack.pop_back();
            ans += i - idx - 1;
        }

        buildingStack.push_back({ buildings[i], i });
    }

    while (!buildingStack.empty())
    {
        auto& [h, idx] = buildingStack.back();
        buildingStack.pop_back();

        ans += N - idx - 1;
    }

    cout << ans;

    return 0;
}