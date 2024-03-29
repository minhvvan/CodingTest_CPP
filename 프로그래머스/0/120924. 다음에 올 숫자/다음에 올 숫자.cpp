#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    
    int firstDiff = common[1] - common[0]; 
    int secondDiff = common[2] - common[1]; 
    
    if(secondDiff == firstDiff)
    {
        answer = common[common.size()-1] + firstDiff;
    }
    else
    {
        answer = common[common.size()-1] * secondDiff/firstDiff;
    }
    
    return answer;
}