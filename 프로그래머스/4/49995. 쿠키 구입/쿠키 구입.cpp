#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    
    int Max;
    for(auto num : cookie) Max += num;
    Max /= 2;
    
    for(int i = 1; i < cookie.size(); i++)
    {
        int l = i-1;
        int r = i;
        
        int leftSum = cookie[l];
        int rightSum = cookie[r];
        
        while(true)
        {
            if(leftSum == rightSum)
            {
                answer = max(answer, leftSum);
            }

            if(leftSum > rightSum){
                if(r + 1 == cookie.size()) break;
                rightSum += cookie[++r];
            }
            else{
                if(l - 1 < 0) break;
                leftSum += cookie[--l];
            }  
        }
    }

    return answer;
}