#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const long long INF = 1e18;
int N,M,K;
vector<pair<int,int> > adj[100001];
vector<int> finish;
vector<long long> dist;
vector<long long> num;

void dijkstra()
{
	priority_queue<pair<long long, long long> > pq;
	for(int i=0; i<K; i++) {
		pq.push(make_pair(0,finish[i]));
		dist[finish[i]] = 0;
		num[finish[i]] = finish[i];
	}
	while( !pq.empty() ) {
		long long here = pq.top().second;
		long long cost = -pq.top().first;
		pq.pop();
		if( dist[here] < cost )
			continue;

		for(int i=0; i<adj[here].size(); i++) {
			long long there = adj[here][i].first;
			long long d = cost + adj[here][i].second;
			if( dist[there] > d ) {
				dist[there] = d;
				num[there] = num[here];
				pq.push(make_pair(-d, there));
			}
			else if( dist[there] == d )
				num[there] = min(num[there], num[here]);
		}
	}
}

int main(void)
{
	setbuf(stdout,NULL);
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		for(int i=0; i<100001; i++)
			adj[i].clear();
		scanf("%d %d %d", &N, &M, &K);
		for(int i=0; i<M; i++) {
			int u,v,w;
			scanf("%d %d %d", &u, &v, &w);
			adj[u].push_back(make_pair(v,w));
			adj[v].push_back(make_pair(u,w));
		}
		dist = vector<long long>(N+1, INF);
		num = vector<long long>(N+1, 0);
		finish.clear();
		for(int i=0; i<K; i++) {
			int a;
			scanf("%d", &a);
			finish.push_back(a);
		}
		
		dijkstra();

		long long ret1 = 0;
		long long ret2 = 0;
		for(int i=1; i<=N; i++) {
			ret1 += dist[i];
			ret2 += num[i];
		}
		printf("Case #%d\n%lld\n%lld\n", test+1, ret1, ret2);
	}
}