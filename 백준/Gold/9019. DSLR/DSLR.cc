#include <bits/stdc++.h>

using namespace std;

int T;
int A, B;

// n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
int D(int num)
{
	return (num * 2) % 10000;
}

//n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
int S(int num)
{
	int result = num - 1;
	if (num == 0) return 9999;

	return result;
}

//n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
int L(int num)
{
	int first = num / 1000;
	return (num * 10) % 10000 + first;
}

//n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.
int R(int num)
{
	int last = num % 10;
	return (num / 10) + 1000 * last;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> T;

	while (T--)
	{
		cin >> A >> B;

		queue<pair<int, string>> q;
		vector<bool> visited(10000, false);
		q.push({ A, "" });
		visited[A] = true;

		while (!q.empty())
		{
			auto [current, oper] = q.front();
			q.pop();

			int d = D(current);
			if (d == B)
			{
				cout << oper + "D" << "\n";
				break;
			}

			if (!visited[d])
			{
				q.push({ d, oper + "D" });
				visited[d] = true;
			}

			int s = S(current);
			if (s == B)
			{
				cout << oper + "S" << "\n";
				break;
			}

			if (!visited[s])
			{
				q.push({ s, oper + "S" });
				visited[s] = true;
			}

			int l = L(current);
			if (l == B)
			{
				cout << oper + "L" << "\n";
				break;
			}

			if (!visited[l])
			{
				q.push({ l , oper + "L" });
				visited[l] = true;
			}

			int r = R(current);
			if (r == B)
			{
				cout << oper + "R" << "\n";
				break;
			}

			if (!visited[r])
			{
				q.push({ r , oper + "R" });
				visited[r] = true;
			}
		}
	}


	return 0;
}