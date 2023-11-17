#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    map<string, int> mapedColothes;
    
    for(auto cloth : clothes)
    {
        mapedColothes[cloth[1]]++;
    }
       
    
//     for(int i = 1; i < (1 << mapedColothes.size()); i++)
//     {
//         int j = 0;
//         int temp = 1;
        
//         auto iter = mapedColothes.begin();
//         for(; iter != mapedColothes.end(); iter++)
//         {
//             if(i & (1<<j++))
//             {
//                 temp *= iter->second;
//             }
//         }
        
//         answer += temp;
//     }
    
    int temp = 1;
    auto iter = mapedColothes.begin();
    for(; iter != mapedColothes.end(); iter++)
    {
        temp *= iter->second + 1;
    }
    
    temp--;
    
    return temp;
}