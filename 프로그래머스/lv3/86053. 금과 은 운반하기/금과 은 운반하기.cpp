#include <string>
#include <vector>
#include <set>

using namespace std;

bool possible(int a, int b, vector<int>& g, vector<int>& s, vector<int>& w, vector<int>& t, long long time)
{
    int n = g.size();
    long long total = 0;
    long long goldSum = 0;
    long long silverSum = 0;

    for (int i = 0; i < n; i++) {
        long long cnt = time / (2 * t[i]);
        if ((time / t[i]) % 2 == 1) cnt++;

        //옮길 수 있는 무게(금+은)
        long long temp = min(cnt * w[i], static_cast<long long>(g[i] + s[i]));
        
        //전체 무게
        total += temp;
        
        //옮길 수 있는 금, 은
        goldSum += min(temp, static_cast<long long>(g[i]));
        silverSum += min(temp, static_cast<long long>(s[i]));
    }

    if (total >= a+b && goldSum >= a && silverSum >= b) return true;
    return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    long long high = 1e9 * 2 * 1e5 * 2;
    long long low = 0;
    
    while(low + 1 < high)
    {
       long long mid = (low + high) / 2;

        if (possible(a, b, g, s, w, t, mid)) high = mid;
        else low = mid;
    }
    
    return high;
}