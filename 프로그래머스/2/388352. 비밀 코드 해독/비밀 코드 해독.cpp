#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int answer = 0;
int N;
vector<int> comb;
vector<vector<int>> Q;
vector<int> Ans;

void Print(vector<int>& temp)
{
    for(auto c : temp)
    {
        cout << c << " ";
    }
}

bool Check()
{
    for(int i = 0; i < Q.size(); i++)
    {
        int cnt = 0;
        for(int j = 0 ; j < 5; j++)
        {
            if(Q[i][comb[j]]) cnt++;
        }
        
        if(cnt != Ans[i]) return false;
    }
    
    return true;
}

void MakeComb(int last)
{
    if(comb.size() == 5)
    {
        if(Check()) answer++;
        return;
    }
    
    for(int i = last; i <= N; i++)
    {
        comb.push_back(i);
        MakeComb(i+1);
        comb.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) 
{
    N = n;
    Ans = move(ans);
    
    Q.resize(q.size(), vector<int>(n+1, 0));
    
    for(int i = 0 ; i < q.size(); i++)
    {
        for(auto num : q[i])
        {
            Q[i][num]++;
        }
    }
    
    MakeComb(1);
        
    return answer;
}