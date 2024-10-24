#include <bits/stdc++.h>

using namespace std;

int N, M, K;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N >> M >> K;

    //0: 가로
    //1: 세로

    vector<int> rowCuts = { 0,M };
    vector<int> colCuts = { 0,N };
    for (int i = 0; i < K; i++)
    {
        int type, idx;
        cin >> type >> idx;

        if(type == 0) rowCuts.push_back(idx);
        else colCuts.push_back(idx);
    }

    std::sort(rowCuts.begin(), rowCuts.end());
    std::sort(colCuts.begin(), colCuts.end());
    
    int rowGap = 0;
    for (int i = 1; i < rowCuts.size(); i++)
    {
        rowGap = max(rowGap, rowCuts[i] - rowCuts[i-1]);
    }

    int colGap = 0;
    for (int i = 1; i < colCuts.size(); i++)
    {
        colGap = max(colGap, colCuts[i] - colCuts[i-1]);
    }

    cout << rowGap * colGap;

    return 0;
}