#include <bits/stdc++.h>

using namespace std;

int T, K;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
map<int, int> cntMap;

void Insert(int num)
{
	cntMap[num]++;

	maxHeap.push(num);
	minHeap.push(num);
}

void Clean()
{
	while (!minHeap.empty() && cntMap[minHeap.top()] == 0) minHeap.pop();
	while (!maxHeap.empty() && cntMap[maxHeap.top()] == 0) maxHeap.pop();
}

void DeleteMin()
{
	if (minHeap.empty()) return;

	cntMap[minHeap.top()]--;
	minHeap.pop();
}

void DeleteMax()
{
	if (maxHeap.empty()) return;

	cntMap[maxHeap.top()]--;
	maxHeap.pop();
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
		cin >> K;
		while (!maxHeap.empty()) maxHeap.pop();
		while (!minHeap.empty()) minHeap.pop();
		cntMap.clear();

		for (int i = 0; i < K; i++)
		{
			char oper;
			int num;

			cin >> oper >> num;

			if (oper == 'I')
			{
				Insert(num);
			}
			else
			{
				if (num == 1) DeleteMax();
				else DeleteMin();

				Clean();
			}
		}

		Clean();
		if (maxHeap.empty()  && minHeap.empty())
		{
			cout << "EMPTY\n";
		}
		else
		{
			cout << maxHeap.top() << " " << minHeap.top() << "\n";
		}
	}
	
	return 0;
}