#include <string>
#include <vector>

using namespace std;

int cnt = 0;

void dfs(int k, vector<vector<int>>& dungeons, vector<bool>& visited, int depth)
{
    cnt = max(cnt, depth);
    
    if(k <= 0)
    {
        return;
    }
    
    for(int i = 0; i < dungeons.size(); i++)
    {
        if(visited[i]) continue;
        
        auto dungeon = dungeons[i];
        int need = dungeon[0];
        int cost = dungeon[1];
        
        if(k < need) continue;
        
        visited[i] = true;
        k -= cost;
        
        dfs(k, dungeons, visited, depth+1);
        
        k += cost;
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    vector<bool> visited(dungeons.size(), false);
    
    dfs(k, dungeons, visited, 0);
    
    return cnt;
}