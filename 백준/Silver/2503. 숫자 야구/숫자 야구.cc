#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;

struct Answer
{
    string num;
    int strike, ball;
};

vector<Answer> answers;

string Convert(int i)
{
    string result;

    for(int k = 0; k < 3; k++)
    {
        result += to_string(i % 10);
        i /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

pair<int, int> Match(string a, string b)
{
    int strike = 0;
    int ball = 0;

    for (int i = 0; i < 3; i++)
    {
        if (a[i] == b[i]) strike++;
        if (a[i] == b[(i + 1) % 3] || a[i] == b[(i + 2) % 3]) ball++;
    }

    return { strike, ball };
}

bool CheckPossible(int i)
{
    int a, b, c;
    c = i % 10;
    b = i / 10 % 10;
    a = i / 100;

    if (a == 0 || b == 0 || c == 0) return false;
    return a != b && b != c && a != c;
}

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string num;
        cin >> num;

        int strike, ball;
        cin >> strike >> ball;

        answers.push_back({ num, strike, ball });
    }
    
    int cnt = 0;
    for (int i = 111; i <= 999; i++)
    {
        if (!CheckPossible(i)) continue;
        string num = Convert(i);

        bool flag = true;
        for (auto& ans : answers)
        {
            auto [s, b] = Match(num, ans.num);
            if (s != ans.strike || b != ans.ball)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
} 