#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> nums;

int gcd(int a, int b) 
{
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;

    cin >> N;
    nums.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

	vector<int> LtoR(N);
	vector<int> RtoL(N);

	LtoR[0] = nums[0];
	RtoL[N - 1] = nums.back();

	for (int i = 1; i <= N - 1; i++)
	{
		LtoR[i] = gcd(LtoR[i - 1], nums[i]);
	}

	for (int i = N - 2; i >= 0; i--) 
	{
		RtoL[i] = gcd(RtoL[i + 1], nums[i]);
	}

	int result = RtoL[1] < LtoR[N - 2] ? LtoR[N - 2] : RtoL[1];
	int except = RtoL[1] < LtoR[N - 2] ? nums[N - 1] : nums[0];

	for (int i = 1; i < N - 1; i++)
	{
		int current = gcd(LtoR[i - 1], RtoL[i + 1]);
		if (result < current)
		{
			result = current;
			except = nums[i];
		}
	}

	if (except % result == 0) 
	{
		cout << "-1";
	}
	else 
	{
		cout << result << " " << except;
	}
    
    return 0;
}