#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int G, P;
vector<int> planes;

int main() 
{
    INPUT_OPTIMIZE;

    cin >> G >> P;

    for (int i = 1; i <= G; i++)
    {
        planes.push_back(i);
    }

    for (int i = 0; i < P; i++)
    {
        if (planes.size() == 0)
        {
            cout << i;
            return 0;
        }

        int g;
        cin >> g;

        int pos = lower_bound(planes.begin(), planes.end(), g) - planes.begin();
        if (pos >= planes.size()) pos = planes.size() - 1;
        if (planes[pos] > g) pos--;

        if(pos < 0)
        {
            cout << i;
            return 0;
        }

        planes.erase(planes.begin() + pos);
    }

    cout << P;

    return 0;
} 