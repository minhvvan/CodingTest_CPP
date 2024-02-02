#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

bool CheckCache(string& city, list<string>& cache)
{
    for(auto itr = cache.begin(); itr != cache.end(); itr++)
    {
        if(*itr == city)
        {
            cache.erase(itr);
            cache.push_back(city);
            return true;
        }
    }
    
    return false;
}

void Convert(string& str)
{
    for(auto& c : str)
    {
        c = tolower(c);
    }
}


int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    list<string> cache;
    
    for(auto city : cities)
    {
        Convert(city);
        
        if(CheckCache(city, cache)) answer++;
        else
        {
            answer += 5;
            if(!cache.empty() && cache.size() == cacheSize)
            {
                cache.pop_front();
            }
            
            if(cacheSize != 0)
            {
                cache.push_back(city);
            }
        }
    }
    
    return answer;
}