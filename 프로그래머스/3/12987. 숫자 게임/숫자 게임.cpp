#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

enum
{
    E_A,
    E_B
};


bool cmp(pair<int,int>& a, pair<int,int>& b)
{
    if(a.first == b.first)
    {
        return a.second > b.second;
    }

    return a.first < b.first;
}

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    vector<pair<int, int>> total;
    
    for(int i = 0 ; i < A.size(); i++)
    {
        total.push_back({A[i], E_A});
        total.push_back({B[i], E_B});
    }
    
    sort(total.begin(), total.end(), cmp);
    
    int Acnt = 0;
    
    for(auto t : total)
    {
        if(t.second == E_B)
        {
            if(Acnt > 0)
            {
                answer++;
                Acnt--;
            }
        }
        else Acnt++;
    }
    
    return answer;
}