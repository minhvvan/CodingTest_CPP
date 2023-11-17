#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    
    vector<int> diff;
    
    if(rocks.size() == n)
    {
        return distance;
    }
    
    diff.push_back(rocks[0]);
    
    for(int i = 0; i < rocks.size()-1; i++)
    {
        diff.push_back(rocks[i+1] - rocks[i]);
    }
    
    diff.push_back(distance - rocks[rocks.size()-1]);
    
    int left = 0;
    int right = distance;
    int mid = (left + right) / 2;
    while(left+1 < right)
    {
        int removedStone = 0;
        int currentDist = 0;
        for(auto dist : diff)
        {
            currentDist += dist;
            
            if(currentDist < mid) removedStone++;
            else currentDist = 0;
        }
        
        if(removedStone > n) right = mid;
        else left = mid;
        
        mid = (left + right) / 2;
    }
    
    
    return mid;
}