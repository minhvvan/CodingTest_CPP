#include <iostream>

using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    
    double line = -static_cast<double>(h)/w;
    
    for(int i = 1; i < w; i++)
    {
        answer += static_cast<int>(line * i + h) * 2;
    }
    
    return answer;
}