#include <bits/stdc++.h>

using namespace std;

int N;

void Parse(string input)
{
	deque<char> front;
	deque<char> rear;

	for (int i = 0; i < input.length(); i++)
	{
		auto letter = input[i];

		if (letter == '<')
		{
			if (front.empty()) continue;
			auto c = front.back();
			front.pop_back();
			rear.push_front(c);
		}
		else if (letter == '>')
		{
			if (rear.empty()) continue;
			auto c = rear.front();
			rear.pop_front();
			front.push_back(c);
		}
		else if (letter == '-')
		{
			if (front.empty()) continue;
			front.pop_back();
		}
		else
		{
			front.push_back(letter);
		}
	}

	for (auto c : front)
	{
		cout << c;
	}
	for (auto c : rear)
	{
		cout << c;
	}

	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;

	cin >> N;

	while (N--)
	{
		string pwd;
		cin >> pwd;

		Parse(pwd);
	}

	return 0;
}