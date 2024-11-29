#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> seatCnt;
vector<bool> hasSeat;
int ans = 0;

struct Dist
{
    Dist() = default;
    Dist(int d, int s, int p) : dist(d), seatIdx(s), peopleIdx(p) {};

    int dist;
    int seatIdx;
    int peopleIdx;

    bool operator < (const Dist& other) const
    {
        return dist < other.dist;
    }
};

void Flush(vector<int>& temp)
{
    for (auto seat : temp)
    {
        seatCnt[seat]++;
    }

    temp.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N >> M;

    vector<pair<int, int>> seats;
    vector<pair<int, int>> people;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char current;
            cin >> current;
            if (current == 'L') seats.push_back({ i,j });
            if (current == 'X') people.push_back({ i,j });
        }
    }

    vector<Dist> dists;

    //make Dist
    for (int i = 0; i < seats.size(); i++)
    {
        auto [seatY, seatX] = seats[i];

        for (int j = 0; j < people.size(); j++)
        {
            auto [personY, personX] = people[j];

            int d = (seatY - personY) * (seatY - personY) + (seatX - personX) * (seatX - personX);
            dists.push_back({ d, i, j });
        }
    }

    sort(dists.begin(), dists.end());

    hasSeat.resize(people.size(), false);
    seatCnt.resize(seats.size(), 0);

    vector<int> temp;
    int previousDistance = -1;

    for(auto [dist, seatIdx, peopleIdx] : dists)
    {
        if (previousDistance < dist)
        {
            previousDistance = dist;
            Flush(temp);
        }

        if (hasSeat[peopleIdx] || seatCnt[seatIdx]) continue;

        hasSeat[peopleIdx] = true;
        temp.push_back(seatIdx);
    }

    if (!temp.empty()) Flush(temp);

    for (int cnt : seatCnt)
    {
        if (cnt >= 2) ans++;
    }

    cout << ans;

    return 0;
}