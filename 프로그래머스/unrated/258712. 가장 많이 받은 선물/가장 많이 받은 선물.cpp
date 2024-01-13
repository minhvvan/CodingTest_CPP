#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int getIdx(string name, vector<string>& friends)
{
    for(int i = 0; i < friends.size(); i++)
    {
        if(friends[i] == name) return i;
    }
    
    return 0;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    //더 많이 준 사람이 다음달에 하나 받음
    //아니면 선물지수가 더 큰 사람이 받음
    //선물 지수는 준 선물 - 받은 선물
    //다 같으면 안받음 
    
    //가장 많이 받을 친구가 받을 선물 수

    //2차원 벡터 만들고 공백 기준으로 나눠서 추가
    //선물지수 벡터도 만들고
    //계산
    
    vector<vector<int>> arr(friends.size(), vector<int>(friends.size(), 0));
    vector<int> giftNum(friends.size(), 0);
    
    for(auto gift : gifts)
    {
        vector<string> names;
        stringstream ss(gift);
        string temp;
 
        while (getline(ss, temp, ' ')) {
            names.push_back(temp);
        }
        
        int from = getIdx(names[0], friends);
        int to = getIdx(names[1], friends);
 
        arr[from][to]++;
    }
    
    
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0 ; j < arr.size(); j++)
        {
            giftNum[i] += arr[i][j];
        }
        
        for(int j = 0 ; j < arr.size(); j++)
        {
            giftNum[i] -= arr[j][i];
        }
    }
    
    
    for(int i = 0; i < arr.size(); i++)
    {
        int now = 0;
        for(int j = 0 ; j < arr.size(); j++)
        {
            if(arr[i][j] > arr[j][i])
            {
                now++;
            }
            else if(arr[i][j] == arr[j][i])
            {
                //선물지수
                if(giftNum[i] > giftNum[j])
                {
                    now++;
                }
            }
        }
        
        answer = max(answer, now);
    }
    
    return answer;
}