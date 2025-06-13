#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
vector<string> guitars;

bool cmp(string& a, string& b)
{
	auto aLen = a.length();
	auto bLen = b.length();

	if (aLen != bLen) return aLen < bLen;

	int aSum = 0, bSum = 0;
	for (int i = 0; i < aLen; i++)
	{
		if ('0' <= a[i] && a[i] <= '9') aSum += a[i] - '0';
		if ('0' <= b[i] && b[i] <= '9') bSum += b[i] - '0';
	}

	if (aSum != bSum) return aSum < bSum;
	return a < b;
}

int main()
{
	INPUT_OPTIMIZE;

	cin >> N;

	guitars.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> guitars[i];
	}

	sort(guitars.begin(), guitars.end(), cmp);
	
	for (auto& guitar : guitars)
	{
		cout << guitar << "\n";
	}

	return 0;
}