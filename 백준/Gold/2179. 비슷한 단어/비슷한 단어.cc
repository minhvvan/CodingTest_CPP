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
#include <list>
#include <bitset>

using namespace std;

struct Node
{
    char C;
    Node* next[26] = {nullptr, };
    int Idx;

    Node() = default;
    Node(char c, int i) : C(c), Idx(i) {};
};

int N;
vector<string> words;
Node* start;
string prefix;
const int MAX = 20'001;
int first = MAX;

void makeTrie(string word, int i)
{
    Node* cursor = start;
    string temp;
    bool bPossible = true;
    int prevIdx = MAX;

    for (char c : word)
    {
        int idx = c - 'a';
        if (cursor->next[idx] == nullptr)
        {
            cursor->next[idx] = new Node(c, i);
            bPossible = false;
        }
        else
        {
            if (bPossible)
            {
                temp += c;
                prevIdx = min(prevIdx, cursor->next[idx]->Idx);
            }
        }

        cursor = cursor->next[idx];
    }

    if (prefix.length() < temp.length())
    {
        prefix = temp;
        first = prevIdx;
    }
    else if (prefix.length() == temp.length())
    {
        //먼저 나온 단어 기준
        if (prevIdx < first)
        {
            prefix = temp;
            first = prevIdx;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    start = new Node();
    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;

        words.push_back(word);
        makeTrie(word, i);
    }

    int cnt = 0;
    for (auto& word : words)
    {
        bool bMatch = true;
        for (int i = 0 ; i < prefix.length(); i++)
        {
            if (prefix[i] != word[i])
            {
                bMatch = false;
                break;
            }
        }

        if (bMatch)
        {
            cout << word << "\n";
            cnt++;
        }

        if (cnt > 1) break;
    }

    return 0;
}