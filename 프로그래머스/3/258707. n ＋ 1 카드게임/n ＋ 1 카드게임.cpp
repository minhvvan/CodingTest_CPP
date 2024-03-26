#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

bool CheckPossible(unordered_set<int>& hands, int target)
{
    bool bPossible = false;
    for(int num : hands)
    {
        if(hands.count(target-num) == 1)
        {
            hands.erase(num);
            hands.erase(target-num);
            bPossible = true;
            
            break;
        }
    }
    
    return bPossible;
}

int solution(int coin, vector<int> cards) {
    int answer = 1;
    
    unordered_set<int> hands;
    unordered_set<int> GetCards;
    
    for(int i = 0; i < cards.size()/3; i++) hands.insert(cards[i]);
    
    int idx = cards.size()/3;
    int target = cards.size()+1;
    
    while(true && idx < cards.size())
    {       
        GetCards.insert(cards[idx]);
        GetCards.insert(cards[idx+1]);
        
        idx+=2;
        
        if(CheckPossible(hands, target))
        {
            answer++;
            continue;
        }
        
        {
            bool bPossible = false;
        
            for(auto num : hands)
            {
                if(GetCards.count(target-num) == 1)
                {
                    hands.erase(num);
                    GetCards.erase(target-num);
                    bPossible = true;
                    
                    break;
                }
            }
            
            if(bPossible && coin >= 1)
            {
                answer++;
                coin--;
                continue;
            }
        }
        
        if(CheckPossible(GetCards, target) && coin >= 2)
        {
            coin -= 2;
            answer++;
            continue;
        }
        
        break;
    }
    
    return answer;
}