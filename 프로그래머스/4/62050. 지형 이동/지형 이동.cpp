#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

struct cmp
{
    bool operator()(tuple<int,int,int>& a, tuple<int,int,int>& b)
    {
        return get<2>(a) > get<2>(b);
    }
};

int Search(vector<vector<int>>& land, priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, cmp>& pq, int cnt, int height, vector<vector<bool>>& visited, int totalCost)
{
    int y;
    int x;
    int cost;
    
    do{
        auto current = pq.top();
        pq.pop();
        
        y = get<0>(current);
        x = get<1>(current);
        cost = get<2>(current);
    }while(visited[y][x] && !pq.empty());
    
    visited[y][x] = true;
    
    if(cnt == land.size() * land[0].size())
    {
        return totalCost + cost;
    }
    
    vector<int> dy = {-1, 0, 1, 0};
    vector<int> dx = {0, 1, 0, -1};
    
    for(int i = 0; i < 4; i++)
    {
        int newY = y + dy[i];
        int newX = x + dx[i];
        
        if(newY < 0 || newY >= land.size() || newX < 0 || newX >= land[0].size()) continue;
        if(visited[newY][newX]) continue;
        
        int addtive = abs(land[newY][newX] - land[y][x]) <= height ? 0 : abs(land[newY][newX] - land[y][x]);
        pq.push({newY, newX, addtive});
    }
    
    return Search(land, pq, cnt+1, height, visited, totalCost+cost);
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    
    vector<vector<bool>> visited(land.size(), vector<bool>(land[0].size(), false));
    
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, cmp> pq;
    pq.push({0,0,0});
    visited[0][0] = true;
    
    answer = Search(land, pq, 1, height, visited, 0);
        
    return answer;
}