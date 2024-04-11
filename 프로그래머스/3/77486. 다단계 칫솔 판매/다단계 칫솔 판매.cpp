#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, int> result;
    map<string, string> parent;
    
    int n = enroll.size();
    
    for(int i = 0; i < n; i++)
    {
        if(referral[i] == "-") parent[enroll[i]] = "center";
        else parent[enroll[i]] = referral[i];
    }
    
    for(int i = 0; i < seller.size(); i++)
    {
        int total = amount[i] * 100;
        
        result[seller[i]] += total * 0.9;
        string pName = parent[seller[i]];
        
        total *= 0.1;
        while(pName != "center" && total >= 1)
        {
            result[pName] += ceil(total * 0.9);
            total *= 0.1;
            
            pName = parent[pName];
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        answer.push_back(result[enroll[i]]);
    }
        
    return answer;
}