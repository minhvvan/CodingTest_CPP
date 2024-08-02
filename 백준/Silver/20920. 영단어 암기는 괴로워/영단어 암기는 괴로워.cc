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

bool cmp(const pair<string, int>& a, const pair<string, int>& b)
{
    if (a.second != b.second) return a.second > b.second;
    if (a.first.length() != b.first.length()) return a.first.length() > b.first.length();
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    map<string, int> wordCnt;
    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        if (word.length() < M) continue;

        wordCnt[word]++;
    }

    vector<pair<string, int>> words;
    for (auto [word, cnt] : wordCnt)
    {
        words.push_back({ word, cnt });
    }

    sort(words.begin(), words.end(), cmp);
    for (auto [word, cnt] : words)
    {
        cout << word << "\n";
    }

    return 0;
}