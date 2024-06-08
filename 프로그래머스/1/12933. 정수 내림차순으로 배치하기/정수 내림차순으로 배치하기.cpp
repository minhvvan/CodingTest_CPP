#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    vector<char> nums;
    while(n > 0)
    {
        nums.push_back(n%10 + '0');
        n /= 10;
    }
    
    sort(nums.begin(), nums.end(), greater());
    
    for(auto num : nums)
    {
        answer *= 10;
        answer += num - '0';
    }
    
    return answer;
}