#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int N, M, K, A, B;
vector<pair<int, int> > D[100000];
int P[100000];
bool T[100000];
int r;

void search(int here, int dest, int dist, bool t)
{
	if( r < dist )
		return;
	if( here == dest ) {
		r = min(r, dist);
		return;
	}

	if( T[here] )
		t = true;

	for(int i=0; i<D[here].size(); i++) {
		int there = D[here][i].first;
		int cost = t?D[here][i].second*B:D[here][i].second*A;
		search(there, dest, dist + cost, t);
	}
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(T, false, sizeof(T));
		scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
		for(int i=0; i<N-1; i++) {
			int x, l;
			scanf("%d %d", &x, &l);
			D[i].push_back(make_pair(x, l));
			D[x].push_back(make_pair(i, l));
		}
		for(int i=0; i<M; i++) {
			scanf("%d", &P[i]);
			P[i]--;
		}
		for(int i=0; i<K; i++) {
			int k;
			scanf("%d", &k);
			T[k-1] = true;
		}
		int ret = 0;
		int start = P[0];
		for(int i=1; i<M; i++) {
			int dest = P[i];
			r = 1234567890;
			search(start, dest, 0, T[start]);
			ret += r;
			start = P[i];
		}
		printf("#%d %d\n", test+1, ret);
	}
	return 0;
}