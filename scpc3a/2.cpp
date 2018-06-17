#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

int N, P;
vector<pair<int,int> > adj[100000];

int search(int start)
{
	vector<bool> added(N, false);
	vector<int> maxWeight(N, 0);
	vector<int> parent(N, -1);
	maxWeight[start] = 1234567890;
	parent[start] = start;
	for(int p=0; p<P; p++) {
		int u = -1;
		for(int v=0; v<N; v++) {
			if(!added[v] && (u==-1 || maxWeight[u] < maxWeight[v] ))
				u = v;
		}

		added[u] = true;
		for(int i=0; i<adj[u].size(); i++) {
			int v = adj[u][i].first;
			int w = adj[u][i].second;
			if( !added[v] && maxWeight[v] < w ) {
				parent[v] = u;
				maxWeight[v] = w;
			}
		}
	}

	int ret = 0;
	for(int i=0; i<N; i++) {
		if( !added[i] && ret < maxWeight[i] )
			ret = max(ret, maxWeight[i]);
	}
	return ret;
}

int main(void)
{
	setbuf(stdout, NULL);
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		for(int i=0; i<100000; i++)
			adj[i].clear();
		scanf("%d", &N);
		int start;
		int weight = 0;
		for(int i=0; i<N-1; i++) {
			int a,b,c;
			scanf("%d %d %d", &a, &b, &c);
			a--;
			b--;
			adj[a].push_back(make_pair(b,c));
			adj[b].push_back(make_pair(a,c));
			if( weight < c ) {
				weight = c;
				start = a;
			}
		}
		scanf("%d", &P);

		int ret = search(start);
		printf("Case %d\n%d\n", test+1, ret);
	}
}