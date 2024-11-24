#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    
    int N = money.size();
    vector<int> dpFirst(money.size()+1, 0);
    vector<int> dpSecond(money.size()+1, 0);
    
    //0번을 선택
    dpFirst[1] = money[0];
    for(int i = 2; i < N; i++)
    {
        dpFirst[i] = max(dpFirst[i-1], dpFirst[i-2] + money[i-1]);
        answer = max(answer, dpFirst[i]);
    }
    
    //0번을 선택 X
    for(int i = 2; i <= N; i++)
    {
        dpSecond[i] = max(dpSecond[i-1], dpSecond[i-2] + money[i-1]);
        answer = max(answer, dpSecond[i]);
    }
    
    return answer;
}