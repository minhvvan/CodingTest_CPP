#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    Node () : num(0-'0'), next(vector<Node*>())  {};
    Node (char n) : num(n), next(vector<Node*>())  {};
    
    char num;
    vector<Node*> next;
};

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    Node* Head = new Node();
    
    {
        auto Cursor = Head;
    
        for(auto c : phone_book[0])
        {
            Cursor->next.push_back(new Node(c));
            Cursor = Cursor->next.back();
        }
    }
    
    
    for(int i = 1; i < phone_book.size(); i++)
    {
        if(!answer) break;
        auto Cursor = Head;
        
        for(int j = 0; j < phone_book[i].size(); j++)
        {
            bool bSame = false;
            for(int k = 0 ; k < Cursor->next.size(); k++)
            {
                if(Cursor->next[k]->num == phone_book[i][j])
                {
                    Cursor = Cursor->next[k];
                    
                    if(Cursor->next.size() == 0) return false;
                    
                    bSame = true;
                    break;
                }
            }
            
            if(!bSame)
            {
                for(int t = j; t < phone_book[i].size(); t++)
                {
                    Cursor->next.push_back(new Node(phone_book[i][t]));
                    Cursor = Cursor->next.back();
                }
                
                break;
            }
        }
    }
    
    
    return answer;
}