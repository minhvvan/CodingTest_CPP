#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

enum {START, END};

struct w_time
{
    int ms, state;
};

int solution(vector<string> lines) {
    vector<w_time> times;
    
    for(auto line : lines)
    {
        stringstream sstr(line);
        string end;
        sstr >> end >> end;
        
        int hh = ((end[0] - '0') * 10 + (end[1] - '0')) * 60 * 60;
        int mm = ((end[3] - '0') * 10 + (end[4] - '0')) * 60;
        int ss = ((end[6] - '0') * 10 + (end[7] - '0'));
        int ms = ((end[9] - '0') * 100 + (end[10] - '0') * 10 + (end[11] - '0'));
        
        ms += ((hh + mm + ss) * 1000);
        
        double work;
        sstr >> work;
        
        times.push_back({ ms - (int)(work * 1000) + 1, START });
        times.push_back({ ms + 999, END });
        
    }
    
    sort(times.begin(), times.end(), [&times](w_time&a, w_time&b) {
    if (a.ms != b.ms)
    {
        return a.ms < b.ms;
    }
    return a.state < b.state;
    });

    int working = 0, max_cnt = 0;
    for (auto time : times)
    {
        if (time.state == START) working++;
        else working--;

        max_cnt = max(working, max_cnt);
    }

    return max_cnt;
}