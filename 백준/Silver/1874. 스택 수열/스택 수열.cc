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
    vector<char> oper;
    int current = 1;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (num < current)
        {
            if (stack.empty() || stack.back() != num)
            {
                cout << "NO";
                return 0;
            }
            else
            {
                stack.pop_back();
                oper.push_back('-');
            }

            continue;
        }

        while (stack.empty() || stack.back() < num)
        {
            oper.push_back('+');
            stack.push_back(current++);
        }

        oper.push_back('-');
        stack.pop_back();
    }

    for (auto op : oper)
    {
        cout << op << "\n";
    }


    return 0;
}