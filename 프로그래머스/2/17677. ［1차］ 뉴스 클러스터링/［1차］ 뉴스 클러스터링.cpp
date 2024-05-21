#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int FindInter(vector<string>& Ja1, vector<string>& Ja2)
{
    int result = 0;
    
    map<string, int> Ja1Cnt;
    map<string, int> Ja2Cnt;
    for(auto j : Ja1) Ja1Cnt[j]++;
    for(auto j : Ja2) Ja2Cnt[j]++;
    
    for(auto itr = Ja1Cnt.begin(); itr != Ja1Cnt.end(); itr++)
    {
        if(Ja2Cnt[itr->first] != 0)
        {
            int cnt1 = itr->second;
            int cnt2 = Ja2Cnt[itr->first];
            
            int minCnt = min(cnt1, cnt2);
            result += minCnt;
        }
    }
    
    return result;
}


int solution(string str1, string str2) {
    int answer = 0;
    
    //집합 간의 유사도
    //교집합 크기를 합집합 크기로 나눈 값
    
    vector<string> Ja1;
    vector<string> Ja2;
    
    for(int i = 0; i < str1.size()-1; i++)
    {
        string temp = "";
        if('a' <= tolower(str1[i]) && tolower(str1[i]) <= 'z') temp += tolower(str1[i]);
        if('a' <= tolower(str1[i+1]) && tolower(str1[i+1]) <= 'z') temp += tolower(str1[i+1]);
        if(temp.size() == 2) Ja1.push_back(temp);
    }
    
    for(int i = 0; i < str2.size()-1; i++)
    {
        string temp = "";
        if('a' <= tolower(str2[i]) && tolower(str2[i]) <= 'z') temp += tolower(str2[i]);
        if('a' <= tolower(str2[i+1]) && tolower(str2[i+1]) <= 'z') temp += tolower(str2[i+1]);
        if(temp.size() == 2) Ja2.push_back(temp);
    }
    
    if(Ja1.size() == 0 && Ja2.size() == 0) return 65536;
    
    int intersectNum = FindInter(Ja1, Ja2);
    int unionNum = Ja1.size() + Ja2.size() - intersectNum;
    
    answer = ((double)intersectNum / unionNum) * 65536;
    
    return answer;
}