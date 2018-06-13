#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, P;
int parent[100000];
int height[100000];
vector<pair<int,int> > tree[100000];
vector<pair<int,pair<int,int> > > w;

int find(int u)
{
	if( u == parent[u] )
		return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if( u == v )
		return;
	if( height[u] > height[v] )
		swap(u,v);
	parent[u] = v;
	if( height[u] == height[v] )
		height[v]++;
}

int isRoot(int start)
{
	start = find(start);
	vector<bool> visited(N,false);
	queue<int> q;
	q.push(start);
	visited[start] = true;
	int num = 1;
	while( !q.empty() ) {
		int here = q.front();
		q.pop();

		for(int i=0; i<tree[here].size(); i++) {
			int there = tree[here][i].first;
			if( !visited[there] && parent[there] == parent[start] ) {
				q.push(there);
				num++;
			}
		}
	}
	if( num == P )
		return start;
	return -1;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		w.clear();
		scanf("%d", &N);
		for(int i=0; i<N; i++) {
			tree[i].clear();
			parent[i] = i;
			height[i] = 1;
		}

		for(int i=0; i<N-1; i++) {
			int a,b,c;
			scanf("%d %d %d", &a, &b, &c);
			a--;
			b--;
			tree[a].push_back(make_pair(b,c));
			tree[b].push_back(make_pair(a,c));
			w.push_back(make_pair(-c,make_pair(a,b)));
		}
		scanf("%d", &P);
		sort(w.begin(), w.end());

		int root = -1;
		for(int i=0; i<w.size(); i++) {
			int u = w[i].second.first;
			int v = w[i].second.second;
			if( find(u) == find(v) )
				continue;
			merge(u,v);
			root = isRoot(u);
			if( root != -1 )
				break;
		}

		int ret = 0;

		printf("Case %d\n%d\n", test+1, ret);
	}
}