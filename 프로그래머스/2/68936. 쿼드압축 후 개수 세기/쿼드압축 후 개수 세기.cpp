#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool CheckRegion(vector<vector<int>>& arr, int y, int x, int size)
{
    int target = arr[y][x];
    
    for(int i = y; i < y+size; i++)
    {
        for(int j = x; j < x+size; j++)
        {
            if(target != arr[i][j]) return false;
        }
    }
    
    return true;
}

void Compress(vector<int>& answer, vector<vector<int>>& arr, int y, int x, int size)
{
    if(y < 0 || y >= arr.size() || x < 0 || x >= arr[0].size()) return;
    
    if(CheckRegion(arr, y, x, size))
    {
        answer[arr[y][x]]++;
        return;
    }
    
    //4개로 분리
    int half = size/2;
    if(half == 0) return;
    
    Compress(answer, arr, y, x, half);
    Compress(answer, arr, y, x+half, half);
    Compress(answer, arr, y+half, x, half);
    Compress(answer, arr, y+half, x+half, half);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    
    answer.push_back(0);
    answer.push_back(0);
    
    Compress(answer, arr, 0, 0, arr.size());
    
    return answer;
}