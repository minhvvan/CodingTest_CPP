#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    //모든 차량 한번은 만나도록 카메라 설치
    //최소 몇대?
    vector<bool> checked(routes.size(), false);
    
    sort(routes.begin(), routes.end(), [](auto a, auto b)
         {
             return a[1] < b[1];
         });
    
    int pos = -30'000;
    
    for(int i = 0; i < routes.size(); i++)
    {
        if(routes[i][0] <= pos) continue;
        
        answer++;
        pos = routes[i][1];
    }
        
    return answer;
}