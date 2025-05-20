#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
long long N;
vector<long long> dice(6);
vector<long long> sum(4, 50*3);

int main() 
{
    INPUT_OPTIMIZE;
    
    cin >> N;

    for (int i = 0; i < 6; i++)
    {
        cin >> dice[i];
        sum[1] = min(sum[1], dice[i]);
    }

    if (N == 1)
    {
        sort(dice.begin(), dice.end());
        int sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum += dice[i];
        }

        cout << sum;
        return 0;
    }

    /*
    * 가장 윗줄은 보여지는 면이 2개, 모서리는 3개
    * 가장 윗줄이 아니면 보여지는 면이 1개, 모서리는 2개
    * 
    * 합이 작아야하기 때문에 붙어있는 세면의 합이 가장 작은게 와야함
    * 
    * 3면이 보이는건 4개 -> ABC = 6 * 4 = 24
    * 2면이 보이는건 4개 -> AB  = 3 * 4 = 12      => 36
    * 
    * 3면이 보이는건 4개 -> 24
    * 2면이 보이는건 12개 -> 3 * 12 = 36
    * 1면이 보이는건 9개 -> 9 => 69
    * 
    * 최대 3면임 -> 조합으로 구해놓자
    * 문제는 보이는 면의 개수를 세는것
    * 가장 윗줄 3면은 무조건 4개
    * 2면이 보이는건 아랫줄부터는 4개씩, 가장 윗줄은 (N-2) * 4
    * 1면이 보이는건 (N-2)^2 * 5
    * 
    * 
    *       +---+        
            | D |        
        +---+---+---+---+
        | E | A | B | F |
        +---+---+---+---+
            | C |        
            +---+    

        2개는 마주보는 면을 빼면 다 가능 합이 5만 아니면 가능
        3개는 ABC, ABD, ACE, ADE, BCF, BDF, CEF, DEF
    */

    //2개 조합
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i == j) continue;
            if (i + j == 5) continue;

            sum[2] = min(sum[2], dice[i] + dice[j]);
        }
    }

    //3개 조합
    sum[3] = min(sum[3], dice[0] + dice[1] + dice[2]);
    sum[3] = min(sum[3], dice[0] + dice[1] + dice[3]);
    sum[3] = min(sum[3], dice[0] + dice[2] + dice[4]);
    sum[3] = min(sum[3], dice[0] + dice[3] + dice[4]);
    sum[3] = min(sum[3], dice[1] + dice[2] + dice[5]);
    sum[3] = min(sum[3], dice[1] + dice[3] + dice[5]);
    sum[3] = min(sum[3], dice[2] + dice[4] + dice[5]);
    sum[3] = min(sum[3], dice[3] + dice[4] + dice[5]);


    /*
    * 가장 윗줄 3면은 무조건 4개
    * 2면이 보이는건 아랫줄부터는 4개씩, 가장 윗줄은 (N-2) * 4
    * 1면이 보이는건 (N-2)^2 * 5
    * 
    */

    long long ans = sum[3] * 4;
    ans += sum[2] * ((N - 2) * 4 + (N - 1) * 4);
    ans += sum[1] * ((N - 1) * (N - 2) * 4 + (N - 2) * (N - 2));

    cout << ans;

    return 0;
} 