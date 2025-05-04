#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, P;
vector<vector<int>> fingers;

int main() 
{
    INPUT_OPTIMIZE;

    /*
    * . 만약, 어떤 줄의 프렛을 여러 개 누르고 있다면, 가장 높은 프렛의 음이 발생한다.
    * (1 ≤ N ≤ 500,000, 2 ≤ P ≤ 300,000)
    * 줄, 프렛
    * 
    * 같은 줄에 높은 음이 오면 안떼는게 이득
    * 패매트릭?
    * 
    */

    cin >> N >> P;

    fingers.resize(N + 1);


    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        if (fingers[a].empty())
        {
            ans++;
            fingers[a].push_back(b);
            continue;
        }

        while (true)
        {
            if (fingers[a].empty())
            {
                ans++;
                fingers[a].push_back(b);
                break;
            }

            auto top = fingers[a].back();

            if (top > b)
            {
                ans++;
                fingers[a].pop_back();
            }
            else if (top == b)
            {
                break;
            }
            else
            {
                ans++;
                fingers[a].push_back(b);
                break;
            }
        }
    }

    cout << ans;

    return 0;
} 