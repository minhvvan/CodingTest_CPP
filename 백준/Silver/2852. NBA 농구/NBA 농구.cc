#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;

struct Time
{
	int h, m;
};

int Convert(string t)
{
	int result = 0;

	result += t[0] - '0';
	result *= 10;
	result += t[1] - '0';

	return result;
}

string Reconvert(int t)
{
	string result;

	if (t < 10)
	{
		result += "0";
		result += t + '0';
	}
	else
	{
		result += (t / 10) + '0';
		result += (t % 10) + '0';
	}

	return result;
}

int team1H = 0;
int team1M = 0;

int team2H = 0;
int team2M = 0;

int team1Score = 0;
int team2Score = 0;

vector<Time> goals;

void Calc(int team, string time)
{
	auto hour = Convert(time.substr(0, 2));
	auto minute = Convert(time.substr(3, 2));

	if (team1Score > team2Score)
	{
		if (!goals.empty())
		{
			auto& [h, m] = goals.back();
			team1H += hour - h;
			team1M += minute - m;

			if (team1M >= 60)
			{
				team1H++;
				team1M -= 60;
			}
			else if (team1M < 0)
			{
				team1H--;
				team1M += 60;
			}
		}
	}
	else if (team1Score < team2Score)
	{
		if (!goals.empty())
		{
			auto& [h, m] = goals.back();
			team2H += hour - h;
			team2M += minute - m;

			if (team2M >= 60)
			{
				team2H++;
				team2M -= 60;
			}
			else if (team2M < 0)
			{
				team2H--;
				team2M += 60;
			}
		}
	}

	if (team == 1) team1Score++;
	else if (team == 2)team2Score++;

	goals.push_back({ hour, minute });
}



int main()
{
	INPUT_OPTIMIZE;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int team;
		string time;

		cin >> team >> time;
		Calc(team, time);
	}

	Calc(0, "48:00");

	cout << Reconvert(team1H) << ":" << Reconvert(team1M) << "\n";
	cout << Reconvert(team2H) << ":" << Reconvert(team2M) << "\n";
	

	return 0;
}