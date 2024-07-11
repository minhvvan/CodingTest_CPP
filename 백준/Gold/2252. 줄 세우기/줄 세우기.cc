#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <climits>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

int N, M;

vector<int> inDegree;
vector<vector<int>> graph;
vector<int> result;

void TopologySort()
{
    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if(inDegree[i]== 0)
        {
            q.push(i);
        }
    }

    for (int i = 1; i <= N; i++) 
    {
        // 총 n번 반복하기 전에 큐가 비어있다면 사이클이 있다는 것
        if (q.empty())   return;
        int cur = q.front(); // 현재 방문한 노드의 번호
        result.push_back(cur); // 방문 결과 저장
        q.pop();

        // 현재 노드와 연결된 노드 중 진입차수가 0인 노드가 있다면 큐에 삽입
        for (auto next : graph[cur])
        {
            if (--inDegree[next] == 0)
            {
                q.push(next);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    graph.assign(N + 1, vector<int>());
    inDegree.assign(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        inDegree[b]++;
    }

    TopologySort();

    for (auto num : result)
    {
        cout << num << " ";
    }

    return 0;
}