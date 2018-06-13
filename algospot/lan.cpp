#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int x[500];
int y[500];
int parent[500];
int height[500];

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

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		scanf("%d %d", &N, &M);
		for(int i=0; i<N; i++) {
			scanf("%d", &x[i]);
			parent[i] = i;
			height[i] = 1;
		}
		for(int i=0; i<N; i++)
			scanf("%d", &y[i]);

		for(int i=0; i<M; i++) {
			int x,y;
			scanf("%d %d", &x, &y);
			merge(x,y);
		}

		vector<pair<double,pair<int,int> > > VE;
		for(int i=0; i<N; i++) {
			for(int j=i+1; j<N; j++) {
				double dist = hypot(x[i]-x[j], y[i]-y[j]);
				VE.push_back(make_pair(dist,make_pair(i,j)));
			}
		}
		sort(VE.begin(), VE.end());
		double ret = 0;
		for(int i=0; i<VE.size(); i++) {
			double dist = VE[i].first;
			int u = VE[i].second.first;
			int v = VE[i].second.second;
			if( find(u) == find(v) )
				continue;
			merge(u,v);
			ret += dist;
		}
		printf("%.10lf\n", ret);
	}
}