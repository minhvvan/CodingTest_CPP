#include <bits/stdc++.h>

using namespace std;

string str;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);  
    
    cin >> str;

    //-를 만나면 뒤에 있는 애들을 모두 더해서 뺌(다른 -를 만나기 전까지)
    //-가 하나면 그대로 종료 bracket안에 있는 애들을 모두 뺌
    //-를 만나지 못하면 모두 더함

    int ans = 0;
    int num = 0;
    bool bMinus = false;
    queue<int> bracket;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '-')
        {
            if (bMinus) bracket.push(num);
            else ans += num;

            bMinus = true;
            num = 0;

            while (!bracket.empty())
            {
                int n = bracket.front();
                bracket.pop();

                ans -= n;
            }
        }
        else if (str[i] == '+')
        {
            if (bMinus) bracket.push(num);
            else ans += num;

            num = 0;
        }
        else
        {
            num *= 10;
            num += str[i] - '0';
        }
    }

    if (bMinus) bracket.push(num);
    else ans += num;

    while (!bracket.empty())
    {
        int n = bracket.front();
        bracket.pop();
        ans -= n;
    }

    cout << ans;

    return 0;
}