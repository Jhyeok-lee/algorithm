#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int V,E,N,M;
vector<pair<int,int> > e[1001];
vector<int> fire;
vector<int> station;

int dijkstra(int start)
{
	priority_queue<pair<int,int> > pq;
	vector<int> dist(V+1,1234567890);
	dist[start] = 0;
	pq.push(make_pair(0,start));
	while( !pq.empty() ) {
		int here = pq.top().second;
		int d = -pq.top().first;
		pq.pop();
		if( d > dist[here] )
			continue;
		for(int i=0; i<e[here].size(); i++) {
			int there = e[here][i].first;
			int next = d + e[here][i].second;
			if( dist[there] > next ) {
				dist[there] = next;
				pq.push(make_pair(-next, there));
			}
		}
	}

	int ret = 1234567890;
	for(int i=0; i<M; i++)
		ret = min(ret, dist[station[i]]);
	return ret;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		for(int i=0; i<1001; i++)
			e[i].clear();
		scanf("%d %d %d %d", &V, &E, &N, &M);
		for(int i=0; i<E; i++) {
			int a,b,t;
			scanf("%d %d %d", &a, &b, &t);
			e[a].push_back(make_pair(b, t));
			e[b].push_back(make_pair(a, t));
		}
		fire = vector<int>(N,0);
		for(int i=0; i<N; i++)
			scanf("%d", &fire[i]);
		station = vector<int>(M,0);
		for(int i=0; i<M; i++)
			scanf("%d", &station[i]);
		int ret = 0;
		for(int i=0; i<N; i++)
			ret += dijkstra(fire[i]);
		printf("%d\n", ret);
	}
	return 0;
}