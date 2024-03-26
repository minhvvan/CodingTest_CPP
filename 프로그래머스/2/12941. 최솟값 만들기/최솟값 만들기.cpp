#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int n = A.size();
    for(int i = 0; i < n; i++)
    {
        answer += A[i] * B[n-i-1];
    }
    
    int temp = 0;
    for(int i = 0; i < n; i++)
    {
        temp += A[n-i-1] * B[i];
    }
    
    answer = min(answer, temp);
    
    return answer;
}