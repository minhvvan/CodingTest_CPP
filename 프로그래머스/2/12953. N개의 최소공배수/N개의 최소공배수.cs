using System;
using System.Linq;

public class Solution {
    
    int GCD(int a, int b)
    {
        if(a < b) (b, a) = (a, b);
        
        if(b == 0) return a;
        return GCD(b, a%b);
    }
    
    public int solution(int[] arr) {
        
        int gcd = GCD(arr[0], arr[1]);
        int num = arr[0] / gcd * arr[1];
        
        for(int i = 1; i < arr.Length; i++)
        {
            gcd = GCD(num, arr[i]);
            num = num * arr[i] / gcd;
        }

        return num;
    }
}