#include <bits/stdc++.h>

using namespace std;

int T, N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> T;

    vector<int> query(T);
    int maxNum = 0;
    for (int i = 0; i < T; i++)
    {
        cin >> query[i];
        maxNum = max(maxNum, query[i]);
    }

    vector<long long> fx(maxNum+1, 0);
    vector<long long> gx(maxNum+1, 0);

    //약수 구하기
    for (int i = 1; i <= maxNum; i++)
    {
        for (int j = i; j <= maxNum; j += i)
        {
            fx[j] += i;
        }
    }

    //누적합
    for (int i = 1; i <= maxNum; i++)
    {
        gx[i] = gx[i - 1] + fx[i];
    }

    for (int i = 0; i < T; i++)
    {
        cout << gx[query[i]] << "\n";
    }

    return 0;
}