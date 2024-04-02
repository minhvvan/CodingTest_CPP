#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <iostream>

using namespace std;

struct Trie {
    bool bFinish; 
    Trie* Node[26];
    int childNum;

    Trie() : bFinish(false), childNum(0) {
        for(int i = 0 ; i < 26; i++) Node[i] = nullptr;
    }

    void insert(const char* Str) {
        childNum++;
        if(*Str == NULL)
        {
            bFinish = true;
            return;
        }
        
        int Cur = *Str - 'a';
        if(Node[Cur] == NULL) Node[Cur] = new Trie();
        
        Node[Cur]->insert(Str + 1);
    }

    int find(const char* key, int depth) {
        if(childNum == 1 || *key == NULL) return depth;
        
        int current = *key - 'a';
        return Node[current]->find(key+1, depth+1);
    }
};

int solution(vector<string> words) {
    int answer = 0;
    
    //트라이
    Trie* Root = new Trie();
    
    for(auto word : words)
    {
        const char *c = word.c_str();
        Root->insert(c);
    }
    
    for(auto word : words)
    {
        const char *c = word.c_str();
        int temp = Root->find(c, 0);
        answer += temp;
    }
    
    
    return answer;
}