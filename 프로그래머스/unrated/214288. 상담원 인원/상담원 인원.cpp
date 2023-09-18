#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

int cal(int k, int n,vector<vector<int>>& reqs)
{
    int waitTime = 0;
    priority_queue<int, vector<int>, greater<int>> endTime;
    for(auto req: reqs)
    {
        int start = req[0];
        int time = req[1];
        int type = req[2];
        
        if(type != k) continue;
        
        if(endTime.size() < n){
            endTime.push(start+time);
            continue;
        }
        
        int firstEnd = endTime.top();
        endTime.pop();
        
        if(start <= firstEnd)
        {
            //대기
            waitTime += (firstEnd-start);
            endTime.push(firstEnd+time);
        }
        else
        {
            endTime.push(start+time);
        }
    }
    
    return waitTime;
}


int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;
    
    vector<int> counselor(k+1, 1);
    vector<vector<int>> wait(k+1, vector<int>(n+1, 0));
    //k유형
    for(int i = 1; i <= k; i++)
    {
        //n명씩 배치
        for(int j = 1; j <= n; j++)
        {
            wait[i][j] = cal(i, j, reqs);
            cout << wait[i][j] << " ";
        }
        cout << "\n";
    }
    
    for(int i = 0; i < n-k; i++)
    {
        int maxVal = 0;
        int maxIdx = 0;
        for(int j = 1; j <= k; j++)
        {
            int idx = counselor[j];
            if(maxVal < wait[j][idx] - wait[j][idx+1])
            {
                maxVal = wait[j][idx] - wait[j][idx+1];
                maxIdx = j;
            }
        }
        counselor[maxIdx]++;
    }
    
    for(int i = 1; i <= k; i++)
    {
        answer += wait[i][counselor[i]];
    }

    
    return answer;
}