#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);  

    cin >> N;

    vector<int> stack;
    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (num == 0)
        {
            if (stack.empty()) continue;
            ans -= stack.back();
            stack.pop_back();
        }
        else
        {
            ans += num;
            stack.push_back(num);
        }
    }

    cout << ans;

    return 0;
}