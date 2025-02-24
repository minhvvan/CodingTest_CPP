#include <bits/stdc++.h>

using namespace std;
using pii=pair<long, long>;

#define MAX 1000001
#define INF 9999999999

vector<pii> vec[MAX];
vector<long> dist(MAX, INF);
long sight[MAX];

long dijkstra(long s, long e){
    priority_queue<pii> pq; pq.push({0, s});
    dist[s]=0;
    
    while(!pq.empty()){
        pii t=pq.top(); pq.pop();
        long c=t.second; long d=t.first*-1;
        
        if(dist[c]<d)continue;
        for(int i=0; i<vec[c].size(); i++){
            long nxt=vec[c][i].first;
            long nxt_d=vec[c][i].second+d;
            if(sight[nxt] == 1 && nxt!=e-1) continue;
            if(nxt_d<dist[nxt]){
                dist[nxt]=nxt_d;
                pq.push({nxt_d*-1, nxt});
            }
        }
    }
    
    return dist[e-1];
    
}
int main(){
    
    long N, M; cin>>N>>M;
    for(int i=0; i<N; i++) cin>>sight[i];
    
    while(M--){
        long a, b, t; cin>>a>>b>>t;
        vec[a].push_back({b, t});
        vec[b].push_back({a, t});
    }
    
    long ans=dijkstra(0, N);
    
    if(ans>=INF) cout<<-1;
    else cout<<ans;

    return 0;
}