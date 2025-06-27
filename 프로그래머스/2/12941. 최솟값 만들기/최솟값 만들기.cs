using System;
using System.Linq;

public class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0;
        
        Array.Sort(A);
        Array.Sort(B);
        
        int size = A.Length;
        for(int i= 0 ; i < size; i++)
        {
            answer += A[i] * B[size - 1 - i];
        }
        
        return answer;
    }
}