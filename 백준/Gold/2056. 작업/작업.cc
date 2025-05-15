#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;
int N;
struct Task
{
    int duration;
    int endTime;
    set<int> preTasks;
    set<int> postTasks;

    Task(int d): duration(d), endTime(0)
    {

    }
};

vector<Task> tasks;
queue<int> q;

void Topology()
{
    while (!q.empty())
    {
        auto idx = q.front();
        q.pop();

        for (auto& post : tasks[idx].postTasks)
        {
            tasks[post].preTasks.erase(idx);
            tasks[post].endTime = max(tasks[post].endTime, tasks[idx].endTime + tasks[idx].duration);

            if (tasks[post].preTasks.empty())
            {
                q.push(post);
            }
        }
    }
}

int main() 
{
    INPUT_OPTIMIZE;

    /*
    * 선행 작업이 없으면 바로 수행(동시 가능)
    * 선행 작업은 무조건 자신보다 번호가 작음
    * 1번은 항상 선행이 없음
    * 선행이 없는건 하나 이상
    * 
    * 선행이 자신보다 무조건 작다 -> 선행이 모두 끝나야 해당 작업이 가능
    * 위상 정렬?
    * 
    * 선행, 후행을 모두 기록
    * 선행이 0이면 q에 추가
    * q에 들어간 애들은 자신의 후행에서 pre를 제거해줌
    * 제거해주면서 pre가 0이되면 q에 추가
    * 끝나는 시간을 같이 기록 -> 끝나는 시간은 max값으로 갱신
    */

    cin >> N;

    //0 -> index맞추기
    tasks.push_back(Task(0));


    for (int i = 1; i <= N; i++)
    {
        int d, p;
        cin >> d >> p;

        tasks.push_back(Task(d));

        for (int j = 0; j < p; j++)
        {
            int t;
            cin >> t;
            tasks[i].preTasks.insert(t);
            tasks[t].postTasks.insert(i);
        }

        if (tasks[i].preTasks.empty())
        {
            q.push(i);
        }
    }

    Topology();

    int ans = 0;
    int idx = 1;
    for (int i =1; i <= N; i++)
    {
        ans = max(ans, tasks[i].endTime + tasks[i].duration);
    }

    cout << ans;

    return 0;
} 