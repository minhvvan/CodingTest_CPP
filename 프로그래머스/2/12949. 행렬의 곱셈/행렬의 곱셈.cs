using System;

public class Solution {
    public int[,] solution(int[,] arr1, int[,] arr2) {
        
        int N = arr1.GetLength(0);
        int M = arr1.GetLength(1);
        
        int[,] answer = new int[N, arr2.GetLength(1)];
        
        for(int i = 0 ; i < N; i++)
        {
            for(int j = 0 ; j < arr2.GetLength(1); j++)
            {
                int result = 0;
                for(int k = 0; k < M; k++)
                {
                    result += arr1[i, k] * arr2[k, j];
                }
                answer[i, j] = result;
            }
        }
        
        return answer;
    }
}