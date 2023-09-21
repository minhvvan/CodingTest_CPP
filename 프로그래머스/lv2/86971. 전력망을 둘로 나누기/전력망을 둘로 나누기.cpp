#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

const int MAX = 999'999'999;

int minDiff = MAX;

int count(int start, vector<vector<int>>& wires)
{
    int cnt = 0;
    
    queue<int> q;
    vector<bool> visited(wires.size());

    q.push(start);
    
    while(!q.empty())
    {
        auto node = q.front();
        q.pop();
        
        if(visited[node]) continue;
        
        visited[node] = true;
        for(auto wire : wires[node])
        {
            q.push(wire);
        }
        
        cnt++;
    }
    
    return cnt;
}

void cut(int n, vector<int>& cutWire, vector<vector<int>>& wires)
{
    vector<vector<int>> temp(n+1);
    for(auto wire : wires)
    {
        if(wire == cutWire) continue;
        
        temp[wire[0]].push_back(wire[1]);
        temp[wire[1]].push_back(wire[0]);
    }
    
    int a = count(cutWire[0], temp);
    int b = count(cutWire[1], temp);
    
    cout << a << " " << b << "\n";
    
    minDiff = min(minDiff, abs(a-b));
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    
    for(auto wire : wires)
    {
        cut(n, wire, wires);
    }
    
    return minDiff;
}