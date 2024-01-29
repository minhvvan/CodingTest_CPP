#include <string>
#include <vector>
#include <iostream>

using namespace std;

void Convert(int num, int n, vector<int>& result)
{
    if(num < n)
    {
        result.push_back(num);
        return;
    }
    
    Convert(num/n, n, result);
    result.push_back(num % n);
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    //0부터 시작해서 1234
    //10이상의 수는 하나씩
    //t * m개를 구해놓고 고르면 됨
        
    vector<int> result;
    for(int i = 0; i <= t * m; i++)
    {
        Convert(i, n, result);
    }
    
    for(int i = 0; i < t; i++)
    {
        if(result[m * i + (p-1)] < 10)
        {
            answer += result[m * i + (p-1)] + '0';
        }
        else
        {
            switch(result[m * i + (p-1)])
            {
                case 10:
                    answer += "A";
                    break;
                case 11:
                    answer += "B";
                    break;
                case 12:
                    answer += "C";
                    break;
                case 13:
                    answer += "D";
                    break;
                case 14:
                    answer += "E";
                    break;
                case 15:
                    answer += "F";
                    break;
            }
        }
    }
    
    return answer;
}