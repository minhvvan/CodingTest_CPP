#include <iostream>

using namespace std;

bool IsMatch(int a, int b)
{
    int nextA = (a-1)/2;
    int nextB = (b-1)/2;
    
    return nextA == nextB;
}

int solution(int n, int a, int b)
{
    int answer = 1;

    //n명 토너먼트(1부터 n)
    //(1,2),(3,4)
    //번호 다시 배정
    //최종 1명
    
    //짝수: /2
    //홀수: /2 + 1
    //같은 슬롯인지 확인 : -1 -> /2
    while(!IsMatch(a, b))
    {
        answer++;
        
        if(a % 2 == 0) a /= 2;
        else 
        {
            a /=2;
            a++;
        }
        
        if(b % 2 == 0) b /= 2;
        else 
        {
            b /=2;
            b++;
        }
    }
    
    
    return answer;
}