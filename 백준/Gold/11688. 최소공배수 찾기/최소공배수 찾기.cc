#include <bits/stdc++.h>

using namespace std;

long long a, b, c, L;

long long gcd(long long y, long long x)
{
    if (x == 0) return y;
    return gcd(x, y % x);
}

long long lcm(long long y, long long x)
{
    return y * x / gcd(y, x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;

    cin >> a >> b >> L;

    long long lcmAB = lcm(a, b);

    if (L % lcmAB != 0)
    {
        cout << "-1" << "\n";
        return 0;
    }

    long long k = L / lcmAB;
    long long c = -1;

	vector<long long> candidates;
	for (long long i = 1; i * i <= lcmAB; i++)
	{
		if (lcmAB % i == 0)
		{
			candidates.push_back(i);
			candidates.push_back(lcmAB / i);
		}
	}

	sort(candidates.begin(), candidates.end());

	bool isFound = false;
	for (int i = 0; i < candidates.size(); i++)
	{
		c = k * candidates[i];
		if (candidates[i] == gcd(lcmAB, c))
		{
			isFound = true;
			break;
		}
	}

	if (isFound == false) c = -1;

	cout << c << "\n";

    return 0;
}