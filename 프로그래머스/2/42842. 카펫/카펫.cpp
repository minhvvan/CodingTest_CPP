#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    //세로 <= 가로
    //yellow를 만들 수 있는 경우의 수를 만들고
    //해당 경우의 수에서 brown이 가능한지
    
    //brown = yellow.X * 2 + yellw.Y * 2 + 4
    
    for(int i = 1; i <= sqrt(yellow); i++)
    {
        if(yellow%i != 0) continue;
        
        int height = i;
        int width = yellow/i;
        
        if(brown == height*2 + width*2 + 4)
        {
            answer.push_back(width+2);
            answer.push_back(height+2);
            break;
        }
    }
    
    return answer;
}