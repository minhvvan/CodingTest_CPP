#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(int n)
{
    if(n < 2) return false;
    bool flag = true;
    
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0) 
        {
            flag = false;
            break;
        }
    }
    
    return flag;
}

int makePer(string numbers, vector<int>& per, vector<bool>& checked, int num, int depth, int max, set<int>& results)
{
    if(depth == max)
    {
        if(results.find(num) != results.end()) return 0;
        
        cout << num << "\n";
        results.insert(num);
        if(isPrime(num)) return 1;
        return 0;
    }
    
    int cnt = 0;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        if(checked[i]) continue;
        
        num *= 10;
        num += numbers[i]-'0';
        checked[i] = true;
        cnt += makePer(numbers, per, checked, num, depth+1, max, results);
        
        num /= 10;
        checked[i] = false;
        cnt += makePer(numbers, per, checked, num, depth+1, max, results);
    }
    
    return cnt;
}

int solution(string numbers) {
    int answer = 0;

    vector<int> temp;
    set<int> results;
    vector<bool> checked(numbers.size(), false);
    
    answer = makePer(numbers, temp, checked, 0, 0, numbers.size(), results);
    return answer;
}