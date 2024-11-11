#include <bits/stdc++.h>

using namespace std;

int T, N;

struct Group
{
    Group(char n, int idx) :
        name(n), lastIndex(idx) {};

    char name;
    int lastIndex;

    bool operator < (const Group& Other)
    {
        return lastIndex < Other.lastIndex;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    //9AAAbbbC22
    cin >> T;

    while (T--)
    {
        cin >> N;

        vector<char> people(N);
        map<char, int> peopleCnt;
        map<char, int> lastIdx;

        for (int i = 0; i < N; i++)
        {
            cin >> people[i];
            peopleCnt[people[i]]++;
            lastIdx[people[i]] = i;
        }

        vector<Group> groups;
        for (int i = 0; i < N; i++)
        {
            groups.push_back(Group(people[i], lastIdx[people[i]]));
        }

        sort(groups.begin(), groups.end());

        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            char current = groups[i].name;
            int groupCnt = peopleCnt[current];

            int lastGroupIdx = i + groupCnt - 1;
            i = lastGroupIdx;

            ans += 5 * (lastIdx[current] - lastGroupIdx) * groupCnt;
        }

        cout << ans << "\n";
    }


    return 0;
}