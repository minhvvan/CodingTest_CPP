#include <stdio.h>
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

const int MAX = 200'020;

int N;

struct ball {
    int size, color, idx;
};

bool cmp(ball& a, ball& b) {
    if (a.size == b.size) return a.color < b.color;
    return a.size < b.size;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<ball> Balls;
    vector<int> Colors(MAX, 0);
    vector<int> Sizes(MAX, 0);
    vector<int> Answer(MAX, 0);

    for (int i = 0; i < N; i++)
    {
        int size, color;
        cin >> color >> size;
        Balls.push_back({ size,color,i });
    }

    sort(Balls.begin(), Balls.end(), cmp);

    int sum = 0;

    for (int i = 0; i < N; i++) 
    {
        int size = Balls[i].size;
        int color = Balls[i].color;
        int idx = Balls[i].idx;

        Answer[idx] = sum - Colors[color] - Sizes[size];

        Colors[color] += size;
        Sizes[size] += size;
        sum += size;

        if (i != 0 && (Balls[i - 1].color == color) && (Balls[i - 1].size == size)) Answer[idx] = Answer[Balls[i - 1].idx];
    }

    for (int i = 0; i < N; i++)
    {
        cout << Answer[i] << "\n";
    }

    return 0;
}