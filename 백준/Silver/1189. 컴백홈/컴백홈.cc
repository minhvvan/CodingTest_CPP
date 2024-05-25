#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <climits>
#include <queue>
#include <map>
#include <set>

using namespace std;

int N, M, K;

vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };

int DFS(vector<vector<char>>& Road, pair<int,int> pos, int dist, vector<vector<bool>>& visited)
{
    if (dist == K)
    {
        if (pos.first == 0 && pos.second == M - 1) return 1;
        else return 0;
    }

    int answer = 0;

    for (int i = 0; i < 4; i++)
    {
        int newY = pos.first + dy[i];
        int newX = pos.second + dx[i];

        if (newY < 0 || newY >= N || newX < 0 || newX >= M) continue;
        if (Road[newY][newX] == 'T') continue;
        if (visited[newY][newX]) continue;

        visited[newY][newX] = true;
        answer += DFS(Road, { newY,newX }, dist + 1, visited);
        visited[newY][newX] = false;
    }

    return answer;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    vector<vector<char>> Road(N, vector<char>(M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
        {
            Road[i][j] = temp[j];
        }
    }

    visited[N - 1][0] = true;
    cout << DFS(Road, {N-1, 0}, 1, visited);

	return 0;
}