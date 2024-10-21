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
#include <unordered_set>
#include <set>
#include <list>
#include <bitset>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);

    cin >> N;

    vector<int> minusMale;
    vector<int> plusMale;
    vector<int> minusFemale;
    vector<int> plusFemale;

    for (int i = 0; i < N; i++)
    {
        int tall;
        cin >> tall;

        if (tall < 0) minusMale.push_back(tall);
        else plusMale.push_back(tall);
    }

    for (int i = 0; i < N; i++)
    {
        int tall;
        cin >> tall;

        if (tall < 0) minusFemale.push_back(tall);
        else plusFemale.push_back(tall);
    }

    sort(minusMale.begin(), minusMale.end());
    sort(plusMale.begin(), plusMale.end());
    sort(minusFemale.begin(), minusFemale.end());
    sort(plusFemale.begin(), plusFemale.end());

    int ans = 0;
    {
        auto itr = plusFemale.rbegin();
        for (int i = 0; i < minusMale.size(); i++)
        {
            int male = abs(minusMale[i]);

            while (itr != plusFemale.rend() && male <= *itr)
            {
                itr++;
            }

            if (itr == plusFemale.rend()) break;

            ans++;
            itr++;
        }   
    }

    {
        auto itr = plusMale.rbegin();
        for (int i = 0; i < minusFemale.size(); i++)
        {
            int female = abs(minusFemale[i]);

            while (itr != plusMale.rend() && female <= *itr)
            {
                itr++;
            }

            if (itr == plusMale.rend()) break;

            ans++;
            itr++;
        }
    }

    cout << ans;


    return 0;
}