#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    for(int T = 0; T < N; T++) {
        int na, nb, t;
        scanf("%d", &t);
        scanf("%d %d", &na, &nb);
        vector<pair<pair<int, int>, int>> times;
        priority_queue<int, vector<int>, greater<int>> apq;
        priority_queue<int, vector<int>, greater<int>> bpq;
        for(int i = 0; i < na + nb; i++) {
            int a, b, c, d;
            scanf("%2d:%2d %2d:%2d", &a, &b, &c, &d);
            if(i < na)
                times.push_back(make_pair(make_pair(a * 60 + b, c * 60 + d), 1));
            else
                times.push_back(make_pair(make_pair(a * 60 + b, c * 60 + d), 2));
        }
        sort(times.begin(), times.end());
        int aans = 0, bans = 0;
        for(int i = 0; i < na + nb; i++) {
            if(times[i].second == 1) { // A -> B
                if(!apq.empty()) {
                    if(apq.top() <= times[i].first.first)
                        apq.pop();
                    else 
                        aans++;
                }
                else
                    aans++;
                bpq.push(times[i].first.second + t);
            }
            else { // B -> A
                if(!bpq.empty()) {
                    if(bpq.top() <= times[i].first.first)
                        bpq.pop();
                    else 
                        bans++;
                }
                else
                    bans++;
                apq.push(times[i].first.second + t);
            }
        }
        printf("Case #%d: %d %d\n", T + 1, aans, bans);
    }
    return 0;
}