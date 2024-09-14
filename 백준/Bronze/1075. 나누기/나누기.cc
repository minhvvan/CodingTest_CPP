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
#include <set>
#include <list>
#include <bitset>

using namespace std;

long long N, F;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int answer = 0;
	cin >> N >> F;

	N -= (N % 100);

	while ((N + answer) % F != 0 && answer < 100) answer++;

	if (answer < 10) printf("0%d", answer);
	else printf("%d", answer);

    return 0;
}