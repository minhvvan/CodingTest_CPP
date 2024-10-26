#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);  
    
    string str;
    while (getline(cin, str))
    {
        if (str == ".") break;
        vector<char> stack;
        bool bCorrect = true;
        for (int i = 0; i < str.length(); i++)
        {
            char current = str[i];
            if (current == '(' || current == '[')
            {
                stack.push_back(current);
                continue;
            }

            if (current == ')')
            {
                if (stack.empty())
                {
                    bCorrect = false;
                    break;
                }

                if (stack.back() != '(')
                {
                    bCorrect = false;
                    break;
                }
                else
                {
                    stack.pop_back();
                }
            }
            else if (current == ']')
            {
                if (stack.empty())
                {
                    bCorrect = false;
                    break;
                }

                if (stack.back() != '[')
                {
                    bCorrect = false;
                    break;
                }
                else
                {
                    stack.pop_back();
                }
            }

            if (!bCorrect) break;
        }

        if (bCorrect && stack.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    
    return 0;
}