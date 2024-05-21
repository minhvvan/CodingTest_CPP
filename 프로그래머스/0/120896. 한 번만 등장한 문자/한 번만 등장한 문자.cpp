#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    map<char, int> StrCnt;
    for(auto c : s)
    {
        StrCnt[c]++;
    }
    
    for(auto itr = StrCnt.begin(); itr != StrCnt.end(); itr++)
    {
        if(itr->second == 1) answer += itr->first;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}