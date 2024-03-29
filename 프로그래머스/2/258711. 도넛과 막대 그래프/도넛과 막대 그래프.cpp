#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

enum
{
    ADDEDNODE,
    DOUNUT,
    STICK,
    EIGHT,
};

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4,0);
    
    //추가한 노드는 모든 노드를 방문할 수 있는 노드
    //단방향: 다시 방문하는 노드가 없이 끝남
    //도넛: 다시방문하는데 더이상 갈곳이 없음
    //8자: 다시방문하는데 갈곳이 있음
    
    int n = 0;
    for(auto& edge : edges)
    {
        n = max(n, edge[0]);
        n = max(n, edge[1]);
    }
    
    vector<vector<int>> graph(n+1);
    vector<int> in(n+1, 0);
    vector<int> out(n+1, 0);
    for(auto& edge : edges) 
    {
        graph[edge[0]].push_back(edge[1]);
        in[edge[1]]++;
        out[edge[0]]++;
    }
    
    
    for(int i = 1; i <= n; i++)
    {
        if(in[i] == 0 && out[i] >= 2) 
        {
            answer[ADDEDNODE] = i;
            break;
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(out[i] == 2 && i != answer[ADDEDNODE]) answer[EIGHT]++;
        if(out[i] == 0 && in[i] >= 1) answer[STICK]++;
    }
    
    answer[DOUNUT] = out[answer[ADDEDNODE]] - answer[EIGHT] - answer[STICK];
    
    return answer;
}