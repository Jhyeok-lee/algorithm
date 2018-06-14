#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int K,L,N,M;
int adj[101][101];

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(adj, 0, sizeof(adj));
		scanf("%d %d %d %d", &K, &L, &N, &M);
		for(int i=0; i<M; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u][v] = 1;
			adj[v][u] = 1;
		}

		int V = N;
		bool cut[101] = {0,};
		bool c = true;
		while( c ) {
			c = false;
			for(int i=1; i<=N; i++) {
				if( cut[i] )
					continue;
				int degree = 0;
				for(int j=1; j<=N; j++) {
					if( adj[i][j] )
						degree++;
				}

				if( degree < K || degree > V-L-1 ) {
					V--;
					for(int j=1; j<=N; j++) {
						adj[i][j] = 0;
						adj[j][i] = 0;
					}
					cut[i] = 1;
					c = true;
				}
			}
		}

		int ret = 0;
		for(int i=1; i<=N; i++) {
			if( cut[i] )
				ret += i;
		}
		printf("Case #%d\n%d\n", test+1, ret);
	}
}