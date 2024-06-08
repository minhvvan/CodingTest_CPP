#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if(arr.size() == 1)
    {
        answer.push_back(-1);
        return answer;
    }
    
    int minNum = INT_MAX;
    for(int i = 0; i < arr.size(); i++)
    {
        minNum = min(minNum, arr[i]);
    }
    
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i]== minNum) continue;
        answer.push_back(arr[i]);
    }
    
    return answer;
}