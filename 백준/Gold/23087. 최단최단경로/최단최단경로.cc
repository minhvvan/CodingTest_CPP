#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const ll mod = 1e9+9;
const ll INF = INT64_MAX/100;
int n,m,x,y;
vector<pi>graph[100005];
ll dist[100005];
ll DIST[100005];
void dijkstra(int start){
	for(int i=1; i<=n; i++) dist[i] = INF;
	dist[start] = 0;
	priority_queue<pi,vector<pi>,greater<pi> >pq;
	pq.push(pi(dist[start],start));
	while(!pq.empty()){
		ll d = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if(d>dist[cur]) continue;
		for(pi p : graph[cur]){
			int nxt = p.first;
			ll w = p.second;
			if(dist[nxt]>d+w){
				dist[nxt] = d+w;
				pq.push(pi(dist[nxt],nxt));
			}
		}
	}
}
void DIJKSTRA(int start){
	DIST[start] = 1;
	queue<int>q; q.push(start);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(pi p : graph[cur]){
			int nxt = p.first;
			ll w = p.second;
			if(dist[nxt]!=dist[cur]+w) continue;
			if(!DIST[nxt]){
				DIST[nxt] = DIST[cur]+1;
				q.push(nxt);
			}
		}
	}
}
ll dp[100005];
ll f(int cur){
	ll&ret = dp[cur];
	if(~ret) return ret;
	ret = 0;
     for (pi p : graph[cur]) {
        int nxt = p.first;
        int w = p.second;
        if (dist[nxt]==dist[cur]+w &&DIST[nxt] == DIST[cur] + 1) ret += f(nxt);
    }
	return ret%=mod;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>n>>m>>x>>y;
	while(m--){
		int a,b,w; cin>>a>>b>>w;
		graph[a].emplace_back(pi(b,w));
	}
	dijkstra(x);
	if(dist[y]==INF) cout<<-1;
	else{
		cout<<dist[y]<<'\n';
		DIJKSTRA(x);
		cout<<DIST[y]-1	<<'\n';
		memset(dp,-1,sizeof(dp));
		dp[y] = 1;
		cout<<f(x);
	}
}