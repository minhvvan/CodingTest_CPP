#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int rightOne = n & -n; 
    int nextHigherOneBit = n + rightOne;
    int rightOnesPattern = n ^ nextHigherOneBit;    
    rightOnesPattern = rightOnesPattern / rightOne; 
    rightOnesPattern = rightOnesPattern >> 2;
    answer = nextHigherOneBit | rightOnesPattern; 
    
    return answer;
}