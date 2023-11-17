#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    vector<pair<string, vector<pair<int,int>>>> PlayCount;
    
    for(int i = 0; i < genres.size(); i++)
    {
        bool bInsert = false;
        for(auto& count : PlayCount)
        {
            if(count.first == genres[i])
            {
                count.second.push_back({i, plays[i]});
                bInsert = true;
                break;
            }
        }
        
        if(!bInsert)
        {
            PlayCount.push_back({genres[i], vector<pair<int,int>>(1,  {i, plays[i]})});
            
        }
    }
    
    sort(PlayCount.begin(), PlayCount.end(), [](const auto lhs, const auto rhs) 
         {
             int sumLhs = 0;
             int sumRhs = 0;
             
             for(auto count : lhs.second)
             {
                sumLhs += count.second;
             }
             
             for(auto count : rhs.second)
             {
                sumRhs += count.second;
             }
             
             return sumLhs > sumRhs;
         });
    
    
    for(auto genre : PlayCount)
    {
        auto& songs = genre.second;
        
        sort(songs.begin(), songs.end(), [](auto lhs, auto rhs) { return lhs.second > rhs.second; });
        
        int cnt = 0;
        for(auto song : songs)
        {
            if(cnt >= 2) break;
            answer.push_back(song.first);
            cnt++;
        }
    }
    
    return answer;
}