#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

int GetIdx(string name, vector<string>& friends)
{
    for(int i = 0 ; i < friends.size(); i++)
    {
        if(friends[i] == name)
        {
            return i;
        }
    }
    
    return -1;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    //두 사람이 주고 받았으면, 많이 준 사람이 받음
    //기록이 없거나 같으면, 선물 지수가 더 큰 사람이 받음
    //선물 지수 = 준 선물 - 받은 선물
    //정확히 같으면 pass
    
    vector<vector<int>> giftLog(friends.size(), vector<int>(friends.size(), 0));
    vector<int> giftNum(friends.size(), 0);
    
    for(auto gift : gifts)
    {
        istringstream iss(gift);
        string from, to;
        
        iss >> from >> to;
        
        int fromIdx = GetIdx(from, friends);
        int toIdx = GetIdx(to, friends);
        
        giftLog[fromIdx][toIdx]++;
    }
    
    //선물 지수
    for(int i = 0; i < friends.size(); i++)
    {
        int giveCnt = 0;
        int recvCnt = 0;
        
        for(int j = 0; j < giftLog[i].size(); j++)
        {
            giveCnt += giftLog[i][j];
        }

        for(int j = 0; j < giftLog.size(); j++)
        {
            recvCnt += giftLog[j][i];
        }
        
        giftNum[i] = giveCnt - recvCnt;
    }
    
    //Solve
    for(int i = 0; i < giftLog.size(); i++)
    {
        int cnt = 0;
        for(int j = 0 ; j < giftLog[i].size(); j++)
        {
            if(i==j) continue;
            if(giftLog[i][j] > giftLog[j][i]) cnt++;
            else if(giftLog[i][j] == giftLog[j][i])
            {
                if(giftNum[i] > giftNum[j]) cnt++;
            }
        }
        
        answer = max(answer, cnt);
    }
    
    return answer;
}