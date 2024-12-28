#include <bits/stdc++.h>

using namespace std;

int N, S = 0;
vector<int> weights;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N;
    weights.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> weights[i];
        S += weights[i];
    }

    //그릇은 항상 왼쪽에 있다
    //오른쪽 추 - 왼쪽추 = 물

    set<int> possibleSet;
    for (int i = 0; i < N; i++)
    {
        int currentWeight = weights[i];
        set<int> temp;
        for (auto comb : possibleSet)
        {
            if(abs(currentWeight - comb) != 0) temp.insert(abs(currentWeight - comb));
            temp.insert(currentWeight + comb);
        }

        for (auto num : temp)
        {
            possibleSet.insert(num);
        }

        possibleSet.insert(currentWeight);
    }

    cout << S - possibleSet.size();

    return 0;
}