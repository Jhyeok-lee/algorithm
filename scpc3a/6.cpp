#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

const long long INF = 1e18;
int N, M;
vector<pair<int,int> > tree[2000];
vector<int> parent;
vector<int> parentWeight;
vector<int> adj[3000];
int capacity[3000][3000];
int flow[3000][3000];
int weight[3000][3000];
bool add[3000][3000];

void init(void)
{
	for(int i=0; i<2000; i++)
		tree[i].clear();
}

void addEdge(int u, int v, int c, int w)
{
	capacity[u][v] = c;
	weight[u][v] = w;
	adj[u].push_back(v);
}

void dfs(int here)
{
	for(int i=0; i<tree[here].size(); i++) {
		int there = tree[here][i].first;
		int weight = tree[here][i].second;
		if( parent[there] == -1 ) {
			parent[there] = here;
			parentWeight[there] = weight;
			dfs(there);
		}
	}
}

void makeGraph()
{
	memset(capacity, 0, sizeof(capacity));
	memset(flow, 0, sizeof(flow));
	memset(weight, 0, sizeof(weight));
	memset(add, 0, sizeof(add));
	for(int i=0; i<3000; i++)
		adj[i].clear();

	int s = N+M;

	for(int i=0; i<N; i++) {
		addEdge(s, M+i, 1, 0);
		addEdge(M+i, i, 1, 0);
		addEdge(M+i, i+N, 1, 0);
	}

	for(int u=0; u<M; u++) {
		for(int i=0; i<tree[u].size(); i++) {
			int v = tree[u][i].first;
			int w = tree[u][i].second;
			addEdge(u,v,N,-w);
		}
	}
	addEdge(M-1,N+M+1,N,0);
}

long long networkFlow(int t)
{
	int V = N+M+2;
	int s = N+M;
	long long ret = 0;
	bool first = true;
	while( true ) {
		vector<int> parent(V, -1);
		vector<long long> dist(V, INF);
		vector<bool> exist(V, false);
		queue<int> q;

		parent[s] = s;
		dist[s] = 0;
		q.push(s);
		exist[s] = true;
		while( !q.empty() ) {
			int here = q.front();
			exist[here] = false;
			q.pop();

			for(int i=0; i<adj[here].size(); i++) {
				int there = adj[here][i];
				if( capacity[here][there] - flow[here][there] > 0 &&
					dist[there] > dist[here] + weight[here][there] ) {
					dist[there] = dist[here] + weight[here][there];
					parent[there] = here;
					if( !exist[there] ) {
						q.push(there);
						exist[there] = true;
					}
				}
			}
		}
		if( parent[t] == -1 )
			break;

		for(int i=t; i!=s; i=parent[i]) {
			if( !add[parent[i]][i] ) {
				ret += weight[parent[i]][i];
				add[parent[i]][i] = true;
			}
			flow[parent[i]][i]++;
			flow[i][parent[i]]--;
		}
	}
	return ret;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		init();
		scanf("%d %d", &N, &M);
		for(int i=0; i<M-1; i++) {
			int u,v,w;
			scanf("%d %d %d", &u, &v, &w);
			if( u > v )
				swap(u,v);
			u--;
			v--;
			tree[u].push_back(make_pair(v,w));
		}
		makeGraph();
		long long ret = networkFlow(N+M+1);
		printf("Case #%d\n%lld\n", test+1, -ret);
	}
	return 0;
}