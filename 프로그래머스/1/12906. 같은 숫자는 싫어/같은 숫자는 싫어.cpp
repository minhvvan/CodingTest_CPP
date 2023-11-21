#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    //0~9
    //연 속은 1개만 
    for(auto num : arr)
    {
        if(answer.size() == 0)
        {
            answer.push_back(num);
            continue;
        }
        
        if(answer.back() == num) continue;
        answer.push_back(num);
    }

    return answer;
}