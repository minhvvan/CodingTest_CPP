#include <bits/stdc++.h>

using namespace std;

struct Tank
{
    Tank() = default;
    Tank(int a, int b, int i) : first(a), second(b), idx(i) {};
    int idx, first, second;

    bool operator < (const Tank& other)
    {
        if (first == other.first)
        {
            return second < other.second;
        }

        return first < other.first;
    }
};

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N;

    vector<Tank> rows(1);
    vector<Tank> cols(1);

    for (int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a >> b;

        rows.push_back({ a, b, i });
        cols.push_back({ b, a, i });
    }

    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());

    /*
        .....
        ..1..
        .234.
        ..5..
        .....

        12...
        3....
        .....
        ....4
        ...56
    */

    deque<int> up;
    deque<int> down;
    deque<int> left;
    deque<int> right;
    for (int i = 1; i <= N; i++)
    {
        if (rows[i].first > i) up.push_back(i);
        else if(rows[i].first < i) down.push_front(i);

        if (cols[i].first > i) left.push_back(i);
        else if (cols[i].first < i) right.push_front(i);
    }

    vector<pair<int, char>> moves;
    //move up
    for (int i = 0; i < up.size(); i++)
    {
        for (int y = up[i]; y < rows[up[i]].first; y++)
        {
            moves.push_back({ rows[up[i]].idx, 'U' });
        }
    }

    //move down
    for (int i = 0; i < down.size(); i++)
    {
        for (int y = rows[down[i]].first; y < down[i]; y++)
        {
            moves.push_back({ rows[down[i]].idx, 'D' });
        }
    }

    //move left
    for (int i = 0; i < left.size(); i++)
    {
        for (int x = left[i]; x < cols[left[i]].first; x++)
        {
            moves.push_back({ cols[left[i]].idx, 'L' });
        }
    }

    //move right
    for (int i = 0; i < right.size(); i++)
    {
        for (int x = cols[right[i]].first; x < right[i]; x++)
        {
            moves.push_back({ cols[right[i]].idx, 'R' });
        }
    }

    cout << moves.size() << "\n";
    for (auto [idx, dir] : moves)
    {
        cout << idx << " " << dir << "\n";
    }

    return 0;
}