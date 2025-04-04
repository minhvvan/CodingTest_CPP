#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N, K;
vector<bitset<26>> words;
bitset<26> learned;
int ans = 0;

bitset<26> Convert(string str)
{
    bitset<26> result;

    for (auto c : str)
    {
        result[c - 'a'] = 1;
    }

    return result;
}

int CanRead()
{
    int cnt = 0;
    for (auto& word : words)
    {
        if ((word & learned).count() == word.count()) cnt++;
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
    
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        words.push_back(Convert(str));
    }

    learned['a' - 'a'] = true;
    learned['t' - 'a'] = true;
    learned['i' - 'a'] = true;
    learned['c' - 'a'] = true;
    learned['n' - 'a'] = true;

    Dfs(0, 5);

    cout << ans;

    return 0;
}