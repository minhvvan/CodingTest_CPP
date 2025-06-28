using System;
using System.Collections.Generic;

public class Solution {
    List<(int, int)> moves = new List<(int, int)>();
    
    public void DFS(int start, int target, int count)
    {
        if(count == 0) return;
        
        int another = 6 - (start + target);
        
        DFS(start, another, count-1);
        moves.Add((start, target));
        DFS(another, target, count-1);
    }
    
    public int[,] solution(int n) {
        DFS(1, 3, n);
        
        int[,] answer = new int[moves.Count, 2];
        for (int i = 0; i < moves.Count; i++)
        {
            answer[i, 0] = moves[i].Item1;
            answer[i, 1] = moves[i].Item2;
        }
        
        return answer;
    }
}