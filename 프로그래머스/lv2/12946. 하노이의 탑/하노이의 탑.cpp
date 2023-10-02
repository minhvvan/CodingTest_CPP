#include <string>
#include <vector>

using namespace std;

enum
{
    ONE_TWO,
    ONE_THREE,
    TWO_ONE,
    TWO_THREE,
    THREE_ONE,
    THREE_TWO
};


vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    vector<vector<vector<vector<int>>>> moved(n+1, vector<vector<vector<int>>>(6));
    
    moved[1][ONE_TWO].push_back({1,2});
    moved[1][ONE_THREE].push_back({1,3});
    moved[1][TWO_ONE].push_back({2,1});
    moved[1][TWO_THREE].push_back({2,3});
    moved[1][THREE_ONE].push_back({3,1});
    moved[1][THREE_TWO].push_back({3,2});
    
    for(int i = 2; i <= n; i++)
    {
        //ONE_TWO
        
        vector<vector<int>> oneTwo;
        oneTwo = moved[i-1][ONE_THREE];
        
        oneTwo.push_back({1,2});
        oneTwo.insert(oneTwo.end(), moved[i-1][THREE_TWO].begin(), moved[i-1][THREE_TWO].end());
        
        moved[i][ONE_TWO] = oneTwo;
        
        
        //ONE_THREE
        
        vector<vector<int>> oneThree;
        oneThree = moved[i-1][ONE_TWO];
        
        oneThree.push_back({1,3});
        oneThree.insert(oneThree.end(), moved[i-1][TWO_THREE].begin(), moved[i-1][TWO_THREE].end());
        
        moved[i][ONE_THREE] = oneThree;
        

        //TWO_ONE
        
        vector<vector<int>> twoOne;
        twoOne = moved[i-1][TWO_THREE];
        
        twoOne.push_back({2,1});
        twoOne.insert(twoOne.end(), moved[i-1][THREE_ONE].begin(), moved[i-1][THREE_ONE].end());
        
        moved[i][TWO_ONE] = twoOne;
        
        
        //TWO_THREE
        
        vector<vector<int>> twoThree;
        twoThree = moved[i-1][TWO_ONE];
        
        twoThree.push_back({2,3});
        twoThree.insert(twoThree.end(), moved[i-1][ONE_THREE].begin(), moved[i-1][ONE_THREE].end());
        
        moved[i][TWO_THREE] = twoThree;
        
        
        //THREE_ONE
        
        vector<vector<int>> threeOne;
        threeOne = moved[i-1][THREE_TWO];
        
        threeOne.push_back({3,1});
        threeOne.insert(threeOne.end(), moved[i-1][TWO_ONE].begin(), moved[i-1][TWO_ONE].end());
        
        moved[i][THREE_ONE] = threeOne;
        
        
        //THREE_TWO
        
        vector<vector<int>> threeTwo;
        threeTwo = moved[i-1][THREE_ONE];
        
        threeTwo.push_back({3,2});
        threeTwo.insert(threeTwo.end(), moved[i-1][ONE_TWO].begin(), moved[i-1][ONE_TWO].end());
        
        moved[i][THREE_TWO] = threeTwo;
        
    }
    
    answer = moved[n][ONE_THREE];
    return answer;
}