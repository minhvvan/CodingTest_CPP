#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    
    for(int i = phone_number.size() - 5; i >= 0; i--)
    {
        phone_number[i] = '*';
    }
    
    answer = move(phone_number);
    return answer;
}