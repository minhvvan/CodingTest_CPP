#include <bits/stdc++.h>

using namespace std;

int N, M;

struct Student 
{
    Student(int a, int c, int o) : ability(a), classNum(c), order(o) {};

    int ability;
    int classNum;
    int order;

    bool operator < (const Student& other) const
    {
        return ability < other.ability;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);  

    cin >> N >> M;

    vector<vector<int>> students(N, vector<int>(M));
    int ans = INT_MAX;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> students[i][j];
        }

        sort(students[i].begin(), students[i].end(), greater());
    }

    priority_queue<Student> pq;
    
    int minNum = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        pq.push(Student(students[i][0], i, 0));
        minNum = min(minNum, students[i][0]);
    }

    while (!pq.empty())
    {
        auto maxStudent = pq.top();
        pq.pop();

        ans = min(ans, maxStudent.ability - minNum);

        if (maxStudent.order == M - 1) break;

        pq.push(Student(students[maxStudent.classNum][maxStudent.order+1], maxStudent.classNum, maxStudent.order + 1));
        minNum = min(minNum, students[maxStudent.classNum][maxStudent.order + 1]);
    }

    cout << ans;

    return 0;
}