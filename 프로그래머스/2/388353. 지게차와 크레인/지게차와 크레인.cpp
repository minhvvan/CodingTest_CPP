#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
vector<vector<char>> Storage;
int n, m;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void Print()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < m; j++)
        {
            cout << Storage[i][j] << " ";
        }
        cout << "\n";
    }
        cout << "\n";
}

bool CheckOuter(int i, int j)
{
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    q.push({i,j});
    visited[i][j] = true;
    
    while(!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();
        
        for(int i = 0 ; i < 4; i++)
        {
            int newY = y + dy[i];
            int newX = x + dx[i];
            
            if(newY < 0 || newY >= n || newX < 0 || newX >= m)
            {
                 return true;
            }
            if(visited[newY][newX]) continue;
            if(Storage[newY][newX] != ' ') continue;
            
            visited[newY][newX] = true;
            q.push({newY, newX});
        }
    }
    
    return false;
}

void Pop(char target)
{
    vector<pair<int,int>> checked;
    
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(Storage[i][j] == target)
            {
                if(CheckOuter(i, j))
                {
                    checked.push_back({i,j});
                }
            }
        }
    }
    
    for(auto& [i,j] : checked)
    {
        Storage[i][j] = ' ';
    }
}

void PopAll(char target)
{
    for(int i = 0 ; i < Storage.size(); i++)
    {
        for(int j = 0;j < Storage[i].size(); j++)
        {
            if(Storage[i][j] == target)
            {
                Storage[i][j] = ' ';
            }
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    n = storage.size();
    m = storage[0].size();
    
    Storage.resize(n, vector<char>(m));
    
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < m; j++)
        {
            Storage[i][j] = storage[i][j];
        }
    }
    
    for(auto& request : requests)
    {
        if(request.length() == 1)
        {
            Pop(request[0]);
        }
        else
        {
            PopAll(request[0]);
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < m; j++)
        {
            if(Storage[i][j] != ' ') answer++;
        }
    }
    
    return answer;
}