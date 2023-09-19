#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    int leftI = left/n;
    int leftJ = left%n;
    
    int rightI = right/n;
    int rightJ = right%n;
    
    // 0,2 ~ 1,2
    
    for(int i = leftI; i <= rightI; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == leftI && j < leftJ) continue;
            if(i == rightI && j > rightJ) break;
            
            answer.push_back(max(i+1, j+1));
        }
    }

    
    return answer;
}