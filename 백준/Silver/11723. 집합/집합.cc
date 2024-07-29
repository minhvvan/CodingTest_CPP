#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <climits>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;
int N;
set<int> S;

void All()
{
    if (S.size() == 20) return;
    S.clear();
    for (int i = 1; i <= 20; i++)
    {
        S.insert(i);
    }
}

void Add(int n)
{
    S.insert(n);
}

void Remove(int n)
{
    S.erase(n);
}

void Check(int n)
{
    cout << S.count(n) << "\n";
}

void Toggle(int n)
{
    if (S.count(n) == 1)
    {
        S.erase(n);
    }
    else
    {
        S.insert(n);
    }
}

void Empty()
{
    S.clear();
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string oper;
        int num;
        cin >> oper;

        if (oper == "all")
        {
            All();
            continue;
        }
        else if (oper == "empty")
        {
            Empty();
            continue;
        }

        cin >> num;

        if (oper == "add") Add(num);
        else if (oper == "remove") Remove(num);
        else if (oper == "check") Check(num);
        else if (oper == "toggle") Toggle(num);
    }
    

    return 0;
}