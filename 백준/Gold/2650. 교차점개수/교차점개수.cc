#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MUL 10000000
int trans(int a,int b) {
	if (a == 1) return b;
	else if (a == 2) return MUL * 2 + MUL - b;
	else if (a == 3) return MUL * 3 + MUL - b;
	else if (a == 4) return MUL + b;
}
int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n/2; i++) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		int p1 = trans(a,b);
		int p2 = trans(c,d);
		if (p1 > p2) swap(p1, p2);
		v.push_back({ p1, p2 });
	}

	int ans = 0, maxn = 0;
	for (int i = 0; i < v.size(); i++) {
		int temp = 0;
		for (int j = 0; j < v.size(); j++) {
			if (i == j) continue;
			pair<int, int> line1 = v[i];
			pair<int, int> line2 = v[j];
			if (line1.first > line2.first) swap(line1, line2);
			if (line1.first < line2.first && line2.first < line1.second && line1.second < line2.second) temp++;
		}
		maxn = max(maxn, temp);
		ans += temp;
	}
	cout << ans/2 << '\n' << maxn;
}