#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for(auto str : s)
    {
        int oneCnt = 0;
        int ooz = 0;
        
        string result;
        
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == '1') oneCnt++;
            else
            {
                if(oneCnt < 2)
                {
                    for(int j = 0; j < oneCnt; j++) result += "1";
                    result += "0";
                    
                    oneCnt = 0;
                }
                else 
                {
                    ooz++;
                    oneCnt -= 2;
                }
            }
        }
        
        for(int i = 0; i < ooz; i++)
        {
            result += "110";
        }
        
        for(int i = 0; i < oneCnt; i++)
        {
            result += "1";
        }
        
        answer.push_back(result);
    }
    
    return answer;
}