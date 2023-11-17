#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp
{
    bool operator() (vector<int>& a, vector<int>& b)
    {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    int time = 0;
    int jobIdx = 0;
    
    sort(jobs.begin(), jobs.end());
    
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    while(jobIdx < jobs.size() || !pq.empty())
    {
        if (jobs.size() > jobIdx && time >= jobs[jobIdx][0]) {
            pq.push(jobs[jobIdx++]);
            continue;
        }
        
        if(!pq.empty())
        {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else
        {
            time = jobs[jobIdx][0];
        }
    }
    
    answer /= jobs.size();
    
    return answer;
}