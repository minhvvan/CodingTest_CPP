#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
//endtime, 개수
queue<pair<int,int>> server;
int total = 0;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    for(int i = 0; i < players.size(); i++)
    {
        int needs = players[i] / m;
        
        while(true)
        {
            if(server.empty()) break;
            auto [endTime, cnt] = server.front();
            if(endTime < i) 
            {
                server.pop();
                total -= cnt;
            }
            else break;
        }
        
        if(total < needs)
        {
            int diff = needs - total;
            server.push({i+k-1, diff});
            total += diff;
            answer += diff;
            
        }
    }
    
    return answer;
}