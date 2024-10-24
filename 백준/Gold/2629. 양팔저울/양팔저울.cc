#include <bits/stdc++.h>

using namespace std;

int N, M;
const int MAX = 40'001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N;

    vector<int> weights(N);
    set<int> Nums;

    for (int i = 0; i < N; i++)
    {
        cin >> weights[i];
    }

    cin >> M;

    vector<int> beads(M);
    for (int i = 0; i < M; i++)
    {
        cin >> beads[i];
    }

    for (int i = N - 1; i >= 0; i--)
    {
        set<int> temp;
        temp.insert(weights[i]);
        for (auto num : Nums)
        {
            if (num - weights[i] > 0) temp.insert(num - weights[i]);
            if (num + weights[i] < MAX) temp.insert(num + weights[i]);
            if (weights[i] - num > 0) temp.insert(weights[i] - num);
        }

        Nums.merge(temp);
    }

    for (auto bead : beads)
    {
        if (Nums.count(bead) == 1) cout << "Y ";
        else cout << "N ";
    }

    return 0;
}