#include <bits/stdc++.h>

using namespace std;

int S, P;
vector<int> passwordNum(4);

bool CheckPossible(vector<int>& password)
{
    bool flag = true;
    for (int i = 0; i < 4; i++)
    {
        if (password[i] < passwordNum[i])
        {
            flag = false;
            break;
        }
    }

    return flag;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> S >> P;

    vector<char> DNA;
    string str;
    cin >> str;
    for (int i = 0; i < S; i++)
    {
        DNA.push_back(str[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        cin >> passwordNum[i];
    }

    vector<int> password(4);
    for (int i = 0; i < P; i++)
    {
        if (DNA[i] == 'A') password[0]++;
        if (DNA[i] == 'C') password[1]++;
        if (DNA[i] == 'G') password[2]++;
        if (DNA[i] == 'T') password[3]++;
    }

    int ans = 0;
    if (CheckPossible(password)) ans++;

    for (int i = 0; i < S - P; i++)
    {
        if (DNA[i] == 'A') password[0]--;
        if (DNA[i] == 'C') password[1]--;
        if (DNA[i] == 'G') password[2]--;
        if (DNA[i] == 'T') password[3]--;

        if (DNA[i+P] == 'A') password[0]++;
        if (DNA[i+P] == 'C') password[1]++;
        if (DNA[i+P] == 'G') password[2]++;
        if (DNA[i+P] == 'T') password[3]++;

        if (CheckPossible(password)) ans++;
    }

    cout << ans;

    return 0;
}