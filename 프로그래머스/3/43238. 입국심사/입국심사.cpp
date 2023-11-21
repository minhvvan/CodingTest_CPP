#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool checkPossible(long long mid, vector<int>& times, int n)
{
    long long cnt = 0;
    for(auto time : times)
    {
        cnt += mid / time;
    }
    
    // cout << cnt << "\n";
    
    return n <= cnt;
}


long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    //입국심사 시간 다름
    //비어있음
    //1심사대 = 1사람
    //이동 가능
    //모든 검사 최소화
    
    long long right = 0;
    for(auto time : times)
    {
        right = max(right, static_cast<long long>(time));
    }
    
    right *= n / times.size();
    long long left = 0;
    long long mid = (left + right) / 2;
    
    while(left + 1 < right)
    {
        // cout << "mid: " << mid << "\n";
        if(!checkPossible(mid, times, n))
        {
            //실패
            left = mid;
        }
        else
        {
            //성공
            right = mid;
        }
        
        mid = (left + right) / 2;
    }
    
    
    return right;
}