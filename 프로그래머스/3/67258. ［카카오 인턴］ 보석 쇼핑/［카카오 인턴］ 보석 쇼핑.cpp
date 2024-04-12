#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
 vector<int> answer(2,0);
    int gSize = gems.size();
    map<string, int> jMap;
    
    int gemCount = 0;

    int head = 0;
    int end = 0;

    int headMin = 0;
    int endMin = 0;

    for (int i = 0; i < gSize; ++i)
    {
        jMap[gems[i]]++;
        // 보석이 1개 있다면 새로운 보석이 추가됨.
        if(jMap[gems[i]] == 1)
        {
            // 보석 갯수 갱신, 최소 구간 갱신
            gemCount++;
            end = i;
            headMin = head;
            endMin = end;
        } else
        {
            //보석이 2개 이상 있다면 기존 구간 좁힘
            end = i;
            for(int j=head;j<i;j++)
            {
                // head 쪽에 2개 이상 있는 경우 1개 제거함.
                if(jMap[gems[j]] > 1)
                {
                    jMap[gems[j]]--;
                } else
                {
                    // 1개만 있는 경우 해당 위치를 구간의 시작으로 잡고 갱신 종료함.
                    head = j;
                    //이때 수정된 구간의 길이가 기존 구간보다 짧으면 구간을 갱신함.
                    if( (end - head) < (endMin - headMin) )
                    {
                        headMin = head;
                        endMin = end;
                    }
                    break;
                }
            }
        }
    }

    answer[0] = headMin+1;
    answer[1] = endMin+1;
    return answer;

    
    return answer;
}