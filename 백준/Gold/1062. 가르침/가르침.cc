#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, K;
vector<string> words;
vector<bool> learned;
int ans = 0;

int CanRead()
{
    int cnt = 0;
    for (auto& word : words)
    {
        bool bPossible = true;
        for (int i = 0; i < word.length(); i++)
        {
            if (learned[word[i] - 'a'] == false)
            {
                bPossible = false;
                break;
            }
        }

        if (bPossible) cnt++;
    }

    return cnt;
}

void Dfs(int idx, int depth)
{
    if (depth == K)
    {
        ans = max(ans, CanRead());
    }

    for (int i = idx; i < 26; i++)
    {
        if (learned[i]) continue;

        learned[i] = true;
        Dfs(i + 1, depth + 1);
        learned[i] = false;
    }
}

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N >> K;
    
    if (K < 5)
    {
        cout << 0;
        return 0;
    }
    
    words.resize(N);
    learned.resize(26, false);

    for (int i = 0; i < N; i++)
    {
        cin >> words[i];
    }

    learned['a' - 'a'] = true;
    learned['t' - 'a'] = true;
    learned['i' - 'a'] = true;
    learned['c' - 'a'] = true;
    learned['n' - 'a'] = true;

    K -= 5;

    Dfs(0, 0);

    cout << ans;

    return 0;
}