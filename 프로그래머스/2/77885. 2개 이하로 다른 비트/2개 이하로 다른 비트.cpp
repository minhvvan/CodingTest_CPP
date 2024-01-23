#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(auto num : numbers)
    {
        //find 0
        long long temp = num;
        int n = 0;
        
        while(temp > 0)
        {
            if(temp % 2 == 0) break;
            
            temp /= 2;
            n++;
        }
        
        if(n == 0) answer.push_back(num+1);
        else
        {
            num += pow(2,n);
            num -= pow(2, n-1);
            
            answer.push_back(num);
        }
    }
    
    return answer;
}