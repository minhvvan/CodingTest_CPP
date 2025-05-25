#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int T, N;
unordered_map<string, vector<string>> clothes;

int main() 
{
    INPUT_OPTIMIZE;
    
    cin >> T;

    while (T--)
    {
        cin >> N;
        clothes.clear();

        for (int i = 0; i < N; i++)
        {
            string name, category;
            cin >> name >> category;

            clothes[category].push_back(name);
        }

        int ans = 0;
        int comb = 1;
        for (auto& cloth : clothes)
        {
            comb *= (cloth.second.size() + 1);
        }

        ans += (comb - 1);

        cout << ans << "\n";
    }

	return 0;
} 