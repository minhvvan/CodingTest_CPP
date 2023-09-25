#include <string>
#include <vector>

using namespace std;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = 0;
    const int MAX = 999'999'999;
    
    int temp = temperature > t2 ? t1 - (temperature - t2) : temperature;
    //외부온도를 0으로 맞춰줌
    t1 -= temp;
    t2 -= temp;
    
    // vector<vector<int>> energy(50, vector<int>(onboard.size(), MAX));
    vector<vector<int>> energy(onboard.size(), vector<int>(t2+2, MAX));
    energy[0][0] = 0;
    
    //시간 진행
    for(int i = 1; i < onboard.size(); i++)
    {
        for(int j = 0; j <= t2 + 1; j++)
        {
            if (onboard[i] == 1 && (j < t1 || j > t2)) continue;
            
            int tempMin = MAX;
            //1. 외부온도 == 목표온도
            if (j == 0) 
            {
                //온도 올리기
                //온도 유지하기
                tempMin = min(tempMin, energy[i-1][j]);
                //온도 내리기
                if (j + 1 <= t2 + 1)
                {
                    tempMin = min(tempMin, energy[i-1][j+1]);
                }
            }
            //2. 외부온도 != 목표온도
            else {
                //온도 올리기
                if (j - 1 >= 0)
                {
                    tempMin = min(tempMin, energy[i-1][j-1] + a);
                }
                
                //온도 유지하기
                tempMin = min(tempMin, energy[i-1][j] + b);
                //온도 내리기
                if (j + 1 <= t2 + 1)
                {
                    tempMin = min(tempMin, energy[i-1][j+1]);
                }
            }
            energy[i][j] = tempMin;
        }
    }
    
    answer = MAX;
    for (int j = 0; j <= t2 + 1; j++)
    {
        answer = min(answer, energy[onboard.size()-1][j]);
    }
    
    return answer;
}