#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int sortIdx = -1;

bool cmp(vector<int>& a, vector<int>& b)
{
    return a[sortIdx] < b[sortIdx];
}


vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    int extIdx = -1;
    if(ext == "code") extIdx = 0;
    else if(ext == "date") extIdx = 1;
    else if(ext == "maximum") extIdx = 2;
    else if(ext == "remain") extIdx = 3;
    
    if(sort_by == "code") sortIdx = 0;
    else if(sort_by == "date") sortIdx = 1;
    else if(sort_by == "maximum") sortIdx = 2;
    else if(sort_by == "remain") sortIdx = 3;
    
    for(auto& d : data)
    {
        if(d[extIdx] < val_ext) answer.push_back(d);
    }
    
    sort(answer.begin(), answer.end(), cmp);
    
    return answer;
}