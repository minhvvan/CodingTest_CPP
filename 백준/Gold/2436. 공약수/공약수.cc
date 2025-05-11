#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int A, B;


int main() 
{
    INPUT_OPTIMIZE;

    cin >> A >> B;

    /*
    * A, B를 최대, 최소로하는 쌍 구하기
    * 두 자연수의 합이 최소가 되는 두 수를 출력한다.
    * 
    * B <= x,y <= A
    * A / B = 최대 공약수를 제외한 나머지 수들 => 이걸 적절히 분배하여 x, y를 만드는데 만든게 합이 최소가 되게 해야 함
    * A / B = k라고해보자
    * k를 소인수 분해하여 합이 작게 만들어야 한다? => prime을 구하기도 해야 함
    * 12 => 3 4 => 7, 2 6 = 8 즉, 가운데서부터 잘라나가야 합이 작다
    * 만약 홀수라면?
    * 
    * 2 2 3
    * 3 3
    * 2 5
    * 2 3 3 
    * 소인수 분해가 아니라 약수 중 가운데있는 애를 선택하는게 유리
    * 1 2 3 6 9 18
    * 1 3 9
    * 1 2 5 10
    * 1 2 4 8 16
    * 약수가 홀수개다? 제곱수이다
    * 제곱수는 그렇게 나눠주면 된다.
    * 
    * 가까운 두수부터 차례대로 벌려나가야함
    * 두 수의 공약수가 없을때까지
    * 공약수를 구하는 방법?
    * 2부터 나눠보기?
    */

    int k = B / A;

    vector<int> nums;

    //k의 약수 구하기
    for (int i = 1; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            nums.push_back(i);
            if (i * i != k)
            {
                nums.push_back(k / i);
            }
        }
    }

    sort(nums.begin(), nums.end());

    int x;
    int y;
    if (nums.size() % 2 == 1)
    {
        int mult = nums[nums.size() / 2];

        x = A * mult;
        y = A * mult;
    }
    else
    {
        int left = nums.size() / 2 - 1;
        int right = nums.size() / 2;

        while (true)
        {
            int leftNum = nums[left];
            int rightNum = nums[right];

            bool hasSame = false;
            for (int i = 2; i * i <= leftNum; i++)
            {
                if (leftNum % i == 0 && rightNum % i == 0)
                {
                    hasSame = true;
                    break;
                }
            }

            if (!hasSame) break;
            left--;
            right++;
        }

        x = A * nums[left];
        y = A * nums[right];
    }

    cout << x << " " << y;

    return 0;
} 