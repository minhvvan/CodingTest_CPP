#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> nums;
vector<int> seg;
int leafSize = 1;

void update(int idx)
{
    int converted = (idx + leafSize) / 2;

    while (converted >= 1)
    {
        seg[converted] = min(seg[converted * 2], seg[converted * 2 + 1]);
        converted /= 2;
    }
}

int getMin(int a, int b)
{
    int left = a + leafSize;
    int right = b + leafSize;

    int result = INT_MAX;
    while (left <= right)
    {
        if (left % 2 == 1) result = min(result, seg[left++]);
        if (right % 2 == 0) result = min(result, seg[right--]);

        left /= 2;
        right /= 2;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N >> M;

    while (leafSize < N)
    {
        leafSize *= 2;
    }

    seg.resize(2 * leafSize + 1, INT_MAX);
    nums.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> nums[i];
        seg[leafSize + i] = nums[i];
    }

    for (int i = 1; i <= N; i += 2)
    {
        update(i);
    }

    vector<pair<int, int>> querise;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << getMin(a, b) << "\n";
    }

    return 0;
}