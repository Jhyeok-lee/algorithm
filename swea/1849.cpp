#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_N 100001

int N,M;
int tree[MAX_N];
int depth[MAX_N];
int weight[MAX_N];

int findRoot(int u)
{
	if( u == tree[u] )
		return u;
	return tree[u] = findRoot(tree[u]);
}

// u + w = v
void merge(int u, int v, int w)
{
	int uw = weight[u];
	int vw = weight[v];
	u = findRoot(u);
	v = findRoot(v);
	if( u == v )
		return;

	if( depth[u] > depth[v] ) {
		swap(u,v);
		swap(uw, vw);
		w *= -1;
	}

	tree[u] = v;
	weight[u] = weight[v] - uw + vw - w;
	if( depth[u] == depth[v] )
		depth[v]++;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(depth, 0, sizeof(depth));
		memset(weight, 0, sizeof(weight));
		scanf("%d %d", &N, &M);
		for(int i=0; i<=N; i++)
			tree[i] = i;

		printf("#%d", test+1);
		for(int i=0; i<M; i++) {
			char c;
			scanf(" %c", &c);
			if( c == '!' ) {
				int u,v,w;
				scanf("%d %d %d", &u, &v, &w);
				merge(u,v,w);
			}
			else {
				int u,v;
				scanf("%d %d", &u, &v);
				if( tree[u] != tree[v] )
					printf(" UNKNOWN");
				else
					printf(" %d", weight[v] - weight[u]);
			}
		}
		printf("\n");
	}
	return 0;
}