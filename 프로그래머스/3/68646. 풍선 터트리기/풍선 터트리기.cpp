#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
    //큰게 없어져서 내게 온다
    //즉, 내 옆에 오는건 양쪽에 있는 가장 작은 수 or 그보다 하나 큰수
    //그게 나보다 크면 무조건 가능
    vector<int> left(a.size(), 0);
    vector<int> right(a.size(), 0);
    
    {
        int currentMin = a[0];
        for(int i = 0; i < a.size(); i++)
        {
            if(currentMin > a[i]) currentMin = a[i];
            left[i] = currentMin;
        }
    }

    {
        int currentMin = a[a.size()-1];
        for(int i = a.size()-1; i >= 0; i--)
        {
            if(currentMin > a[i]) currentMin = a[i];
            right[i] = currentMin;
        }
    }
    
    answer = 2;
    for(int i = 1; i < a.size()-1; i++)
    {
        if(a[i] > left[i] && a[i] > right[i]) continue;
        answer++;
    }
    
    return answer;
}