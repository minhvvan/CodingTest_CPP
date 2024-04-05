#include <vector>
#include <string>
#include <iostream>
#include <climits>
using namespace std;

enum
{
    MINUS,
    PLUS
};

int solution(vector<string> arr)
{
    int answer = -1;
    
    vector<vector<int>> dpMax((arr.size()+1)/2, vector<int>((arr.size()+1)/2, INT_MIN));
    vector<vector<int>> dpMin((arr.size()+1)/2, vector<int>((arr.size()+1)/2, INT_MAX));
    vector<int> nums;
    vector<int> oper;
    for(int i = 0 ; i < arr.size(); i++)
    {
        if(i%2 == 0)
        {
            int num = 0;
            for(auto c : arr[i])
            {
                num *= 10;
                num += c - '0';
            }
            
            nums.push_back(num);
        }
        else
        {
            if(arr[i] == "-") oper.push_back(MINUS);
            else oper.push_back(PLUS);
        }
    }
    
    //1 3 5 8
    //- + -
    for(int i = 0 ; i < nums.size(); i++) 
    {
        dpMax[i][i] = nums[i];
        dpMin[i][i] = nums[i];
    }
    
    for(int i = 0; i < nums.size(); i++)
    {
        for(int start = 0; start < nums.size(); start++)
        {
            int end = start+i;
            
            if(end >= nums.size()) break;
            
            for(int k = start; k < end; k++)
            {
                if(oper[k] == MINUS)
                {
                    dpMin[start][end] = min(dpMin[start][end], dpMin[start][k] - dpMax[k+1][end]);
                    dpMax[start][end] = max(dpMax[start][end], dpMax[start][k] - dpMin[k+1][end]);
                }
                else
                {
                    dpMin[start][end] = min(dpMin[start][end], dpMin[start][k] + dpMin[k+1][end]);
                    dpMax[start][end] = max(dpMax[start][end], dpMax[start][k] + dpMax[k+1][end]);
                }
            }
        }
    }
    
    return dpMax[0][nums.size()-1];
}