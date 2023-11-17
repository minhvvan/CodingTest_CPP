#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end(), [](auto lhs, auto rhs){return lhs > rhs;});
    
    
    //6 5 3 1 0 
    for(int i = 0; i < citations.size(); i++)
    {
        if(answer < citations[i])
        {
            answer++;
        }
    }
    
    return answer;
}