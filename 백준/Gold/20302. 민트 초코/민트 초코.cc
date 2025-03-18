#include <bits/stdc++.h>
using namespace std;

int N, n;
int MAX = 100'000;
vector<int> child(MAX, 0);
void fac(int a, bool check) {
	int tmp = sqrt(a);
	if (check) {
		for (int i = 2; i <= tmp; i++) {
			while (a % i == 0) {
				child[i]++;
				a /= i;
			}
		}
		if (a > 1) child[a]++;
	}
	else {
		for (int i = 2; i <= tmp; i++) {
			while (a % i == 0) {
				child[i]--;
				a /= i;
			}
		}
		if (a > 1) child[a]--;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int inputCnt = 2 * n - 1;
	bool flag = true;
	bool zeroCheck = false;
	string s;
	for (int i = 1; i < inputCnt + 1; i++) {
		cin >> s;
		if (i % 2 == 0) {
			if (s == "*") flag = true;
			else flag = false;
			continue;
		}
		if (s == "0") zeroCheck = true;
		fac(abs(stoi(s)), flag);
	}
	if (zeroCheck) {
		cout << "mint chocolate";
		return 0;
	}
	for (int i = 2; i < 100001; i++) {
		if (child[i] < 0) {
			cout << "toothpaste";
			return 0;
		}
	}
	cout << "mint chocolate";

	return 0;
}