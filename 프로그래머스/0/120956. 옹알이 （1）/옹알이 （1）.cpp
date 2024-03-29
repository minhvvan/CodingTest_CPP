#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    set<string> canSpeak;
    canSpeak.insert("aya");
    canSpeak.insert("ye");
    canSpeak.insert("woo");
    canSpeak.insert("ma");
    
    for(auto& word : babbling)
    {
        string temp;
        for(int i = 0; i < word.size(); i++)
        {
            temp += word[i];
            
            if(canSpeak.count(temp) >= 1)
            {
                temp = "";
            }
        }
        
        if(temp.size() == 0) answer++;
    }
    
    return answer;
}