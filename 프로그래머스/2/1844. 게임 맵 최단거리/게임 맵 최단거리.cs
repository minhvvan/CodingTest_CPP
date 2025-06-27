using System.Collections.Generic;

class Solution {
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, 1, 0, -1};
    
    public int solution(int[,] maps) {
        int answer = -1;
        
        int N = maps.GetLength(0);
        int M = maps.GetLength(1);
        
        bool[,] visited = new bool[N,M];
        
        Queue<(int, int)> q = new Queue<(int, int)>();
        q.Enqueue((0, 0));
        visited[0,0] = true;
        
        int depth = 1;
        while(q.Count > 0)
        {
            int size = q.Count;
            
            for(int t = 0; t < size; t++)
            {
                var (y, x) = q.Dequeue();
            
                for(int i = 0 ; i < 4; i ++)
                {
                    int newY = y + dy[i];
                    int newX = x + dx[i];

                    if(newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
                    if(visited[newY, newX]) continue;
                    if(maps[newY, newX] == 0) continue;
                    if(newY == N-1 && newX == M-1)
                    {
                        answer = depth + 1;
                        break;
                    }

                    visited[newY, newX] = true;
                    q.Enqueue((newY, newX));
                }
                
                if(answer != -1) break;
            }
            
            if(answer != -1) break;
            depth++;
        }
        
        return answer;
    }
}