#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;
vector<int> B;

bool bSame = false;
int cursor = 0;

void IsSame()
{
    for (int i = cursor; i < N; i++)
    {
        if (A[i] != B[i]) return;
        cursor++;
    }
    
    bSame = true;
}

bool Merge(int start, int end, int mid)
{
    int left = start;
    int right = mid+1;

    vector<int> temp;
    while (left <= mid && right <= end)
    {
        if (A[left] <= A[right]) temp.push_back(A[left++]);
        else temp.push_back(A[right++]);
    }

    while (left <= mid)
    {
        temp.push_back(A[left++]);
    }

    while (right <= end)
    {
        temp.push_back(A[right++]);
    }

    bool result = false;
    for (int i = start; i <= end; i++)
    {
        A[i] = temp[i - start];
        if (!bSame) IsSame();
    }

    return result;
}

void MergetSort(int start, int end)
{
    if (start >= end) return;

    int mid = (start + end) / 2;

    MergetSort(start, mid);
    MergetSort(mid + 1, end);
    Merge(start, end, mid);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    cin >> N;

    A.resize(N);
    B.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    bSame = true;
    for (int i = 0; i < N; i++)
    {
        if (A[i] != B[i]) bSame = false;
    }

    if(bSame)
    {
        cout << 1;
        return 0;
    }

    MergetSort(0, N - 1);
        
    if(bSame) cout << 1;
    else cout << 0;

    return 0;
}