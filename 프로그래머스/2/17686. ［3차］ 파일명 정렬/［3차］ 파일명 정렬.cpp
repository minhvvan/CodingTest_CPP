#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

enum
{
    HEAD,
    NUMBER,
    TAIL
};

bool cmp(const vector<string>& a,const vector<string>& b)
{
    //HEAD CMP
    {
        int size = min(a[HEAD].size(), b[HEAD].size());
    
        for(int i = 0; i < size; i++)
        {
            char first = tolower(a[HEAD][i]);
            char second = tolower(b[HEAD][i]);

            if(first == second) continue;
            return first < second;
        }
        
        if(a[HEAD].size() != b[HEAD].size()) return a[HEAD].size() < b[HEAD].size();
    }
    
    //NUMBER CMP
    {
        int aNum = 0;
        int bNum = 0;

        for(int i = 0; i < a[NUMBER].size(); i++)
        {
            aNum *= 10;
            aNum += a[NUMBER][i] - '0';
        }
        
        for(int i = 0; i < b[NUMBER].size(); i++)
        {
            bNum *= 10;
            bNum += b[NUMBER][i] - '0';
        }
        
        return aNum < bNum;
    }

    return false;
}

void Parse(vector<string>& parsedFiles, string& file)
{
    string HEAD;
    string NUMBER;
    string TAIL;
    
    int cursor = 0;
    
    while(0 > file[cursor] - '0' || file[cursor] - '0' > 9)
    {
        if(cursor >= file.size()) break;
        HEAD += file[cursor++];
    }
        
    int maxCursor = cursor + 5;
    while(0 <= file[cursor] - '0' && file[cursor] - '0' <= 9 && cursor < maxCursor)
    {
        if(cursor >= file.size()) break;
        NUMBER += file[cursor++];
    }
        
    for(; cursor < file.size(); cursor++)
    {
        TAIL += file[cursor];
    }
    
    parsedFiles.push_back(HEAD);
    parsedFiles.push_back(NUMBER);
    parsedFiles.push_back(TAIL);
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<vector<string>> parsed;
    for(auto file : files)
    {
        vector<string> temp;
        
        Parse(temp, file);
        parsed.push_back(temp);
    }
    
    stable_sort(parsed.begin(), parsed.end(), cmp);
    
    for(auto parse : parsed)
    {
        string temp;
        
        for(auto str : parse)
        {
            temp += str;            
        }
        
        answer.push_back(temp);
    }
    
    
    return answer;
}