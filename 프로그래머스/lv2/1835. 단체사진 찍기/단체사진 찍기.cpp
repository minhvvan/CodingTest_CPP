#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int cnt= 0;
int out= 0;

void Permutation(vector<string>& data, string temp, string friends1, vector<bool>& visited)
{
    if(temp.size() == 8)
    {
        bool flag = true;
        for(auto d : data)
        {
            if(!flag) 
            {
                break;
            }
            
            int itr1 = temp.find(d[0]);
            int itr2 = temp.find(d[2]);
            
            int diff = abs(itr2 - itr1) - 1;
            if(d[3] == '=')
            {
                if(diff != d[4]-'0') flag = false;
            }
            else if(d[3] == '<')
            {
                if(diff >= d[4]-'0') flag = false;
            }
            else
            {
                if(diff <= d[4]-'0') flag = false;
            }
        }
        
        if(flag)
        {
            cnt++;
        }
        return;
    }
    
    for(int i = 0; i < 8; i++)
    {
        if(visited[i]) continue;
        
        temp += friends1[i];
        visited[i] = true;
        Permutation(data, temp, friends1, visited);
        
        temp.erase(temp.end()-1);   
        visited[i] = false;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    cnt = 0;
    
    string friends1("ACFJMNRT");
    
    vector<string> Per;
    vector<bool> visited(8, false);
    string temp;
    Permutation(data, temp, friends1, visited);
    

    
    return cnt;
}