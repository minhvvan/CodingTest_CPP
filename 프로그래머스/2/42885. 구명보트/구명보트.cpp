#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    //한번에 최대 2명
    //최대한 적은 횟수
    vector<bool> checked(people.size(), false);
    sort(people.begin(), people.end(), [](int a, int b){ return a > b;});
    
    int left = 0;
    int right = people.size()-1;
    int cnt = 0;
    
    while(left < right)
    {
        if(people[left] + people[right] <= limit)
        {
            left++;
            right--;
            cnt += 2;
        }
        else
        {
            left++;
            cnt++;
        }
        
        answer++;
    }
    
    if(cnt != people.size()) answer++;
    
    return answer;
}