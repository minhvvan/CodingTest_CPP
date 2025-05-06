#include <bits/stdc++.h>
using namespace std;
#define INPUT_OPTIMIZE cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2e9

using namespace std;

struct Food
{
    int p, f, s, v, cost;

    Food() {}

    Food(int a, int b, int c, int d) : p(a), f(b), s(c), v(d)
    {
        cost = 0;
    }

    Food* operator += (const Food& other)
    {
        p += other.p;
        f += other.f;
        s += other.s;
        v += other.v;
        cost += other.cost;

        return this;
    }

    void Print()
    {
        cout << p << " " << f << " " << s << " " << v << " " << cost << "\n";
    }
};

int N;
Food target(0,0,0,0);
vector<Food> foods;


bool Check(Food& food)
{
    return target.p <= food.p && target.f <= food.f && target.s <= food.s && target.v <= food.v;
}

int main() 
{
    INPUT_OPTIMIZE;

    cin >> N;

    int p, f, s, v;
    cin >> p >> f >> s >> v;
    target.p = p;
    target.f = f;
    target.s = s;
    target.v = v;

    for (int i = 0; i < N; i++)
    {
        int p, f, s, v, c;
        cin >> p >> f >> s >> v >> c;

        auto food = new Food(p, f, s, v);
        food->cost = c;
        foods.push_back(*food);
    }

    /*
    * dp 인데
    * 부분집합 -> 시간초과?
    */

    int ans = INT_MAX;
    vector<vector<int>> ansIndex;
    for (int i = 1; i < (1 << N); i++)
    {
        Food current(0,0,0,0);
        vector<int> currentIndex;

        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                current += foods[j];
                currentIndex.push_back(j);
            }
        }

        if (Check(current) && current.cost <= ans)
        {
            if (current.cost < ans)
            {
                ans = current.cost;
                ansIndex.clear();
            }

            ansIndex.push_back(currentIndex);
        }
    }

    if (ans == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << ans << "\n";

        sort(ansIndex.begin(), ansIndex.end());
        for (auto idx : ansIndex[0])
        {
            cout << idx + 1 << " ";
        }
    }
    

    return 0;
} 