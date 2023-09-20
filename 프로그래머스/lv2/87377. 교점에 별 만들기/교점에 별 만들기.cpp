#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

const long long MAX = 9'223'372'036'854'775'807;
set<pair<long long,long long>> points;
long long minX = MAX;
long long minY = MAX;
long long maxX = -MAX;
long long maxY = -MAX;

pair<long long, long long> findPoint(vector<int> a, vector<int> b)
{
    // 평행
    long A = static_cast<long>(a[0]);
    long B = static_cast<long>(a[1]);
    long C = static_cast<long>(b[0]);
    long D = static_cast<long>(b[1]);
    long E = static_cast<long>(a[2]);
    long F = static_cast<long>(b[2]);
    
    long det = (A * D) - (B * C);
    if(det == 0) return {MAX, MAX};
    
    long long x = MAX;
    long long y = MAX;
    
    if(((B * F) - (E * D)) % det == 0)
    {
        x = ((B * F) - (E * D)) / det;
    }
    
    if(((E * C) - (A * F)) % det == 0)
    {
        y = ((E * C) - (A * F)) / det;
    }
    
    return {x,y};
}


void dfs(vector<vector<int>>& line, vector<vector<int>>& temp, int idx)
{
    if(temp.size() == 2)
    {
        auto point = findPoint(temp[0], temp[1]);
        
        if(point.first != MAX && point.second != MAX)
        {
            minX = min(minX, point.first);
            minY = min(minY, point.second);
            
            maxX = max(maxX, point.first);
            maxY = max(maxY, point.second);
            points.insert(point);
        }
        return;
    }
    
    for(int i = idx; i < line.size(); i++)
    {
        temp.push_back(line[i]);
        dfs(line, temp, i+1);
        
        temp.pop_back();
    }
}


vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    
    vector<vector<int>> temp;
    dfs(line, temp, 0);
    
    long long rangeX = maxX - minX + 1;
    long long rangeY = maxY - minY + 1;

    for(long long i = 0; i < rangeY; i++)
    {
        string row(rangeX, '.');
        answer.push_back(row);
    }
    
    for(auto p : points)
    {
        long long x = p.first - minX;
        long long y = maxY - p.second;
        
        answer[y][x] = '*';
    }
    
    return answer;
}