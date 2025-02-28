#include <bits/stdc++.h>

using namespace std;

int N, S;
vector<int> nums;
vector<int> sorted;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	
	cin >> N;
	nums.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
		sorted.push_back(nums[i]);
	}

	cin >> S;

	sort(sorted.begin(), sorted.end(), greater<int>());
	
	/*
	* S번만 정렬가능
	* 큰수가 앞으로
	* 버블 -> N-1번만에 최대를 고름+ N-2번만에 두번째를 고름
	* 문제는 결과를 출력해야 하는 것과 S가 N-1,N-2같이 나누어 떨어지지 않을 수 있음
	* S <= 1'000'000
	* 
	* S안에 앞으로 큰수가 오도록해야함
	* 현재 인덱스와 타겟 인덱스를 구하고 안되면 다음 안되면 다음 안되면 다음
	* N <= 50 
	* 
	*/

	for (int i = 0; i < N; i++)
	{
		if (S <= 0) break;

		set<int> checked;
		while (true)
		{
			int maxNum = 0;
			int idx = i;
			for (int j = i; j < N; j++)
			{
				if (nums[j] > maxNum && checked.count(nums[j]) == 0)
				{
					maxNum = nums[j];
					idx = j;
				}
			}

			if (idx - i <= S)
			{
				int num = nums[idx];
				nums.erase(nums.begin() + idx);
				nums.insert(nums.begin() + i, num);

				S -= (idx - i);
				break;
			}
			else
			{
				//다음 큰 수 찾기
				checked.insert(nums[idx]);
			}
		}
	}


	for (auto num : nums)
	{
		cout << num << " ";
	}

	return 0;
}