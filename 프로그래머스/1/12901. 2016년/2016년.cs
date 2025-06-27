using System.Collections.Generic;

public class Solution {
    public string solution(int a, int b) {
        string answer = "";
        List<string> days = new List<string>();
        days.Add("THU");
        days.Add("FRI");
        days.Add("SAT");
        days.Add("SUN");
        days.Add("MON");
        days.Add("TUE");
        days.Add("WED");
        
        Dictionary<int,int> dates = new Dictionary<int,int>();
        dates.Add(1, 31);
        dates.Add(2, 29);
        dates.Add(3, 31);
        dates.Add(4, 30);
        dates.Add(5, 31);
        dates.Add(6, 30);
        dates.Add(7, 31);
        dates.Add(8, 31);
        dates.Add(9, 30);
        dates.Add(10, 31);
        dates.Add(11, 30);
        dates.Add(12, 31);
        
        int total = 0;
        for(int i = 1; i < a; i++)
        {
            total += dates[i];
        }
        
        total += b;
        total %= 7;
        
        answer = days[total];
        
        return answer;
    }
}