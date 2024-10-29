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

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        if (str == "push")
        {
            int num;
            cin >> num;

            stack.push_back(num);
        }
        else if (str == "top")
        {
            if (stack.empty()) cout << -1 << "\n";
            else cout << stack.back() << "\n";
        }
        else if (str == "size")
        {
            cout << stack.size() << "\n";
        }
        else if (str == "empty")
        {
            if (stack.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (str == "pop")
        {
            if (stack.empty()) cout << -1 << "\n";
            else
            {
                int num = stack.back();
                stack.pop_back();
                cout << num << "\n";
            }
        }
    }

    return 0;
}