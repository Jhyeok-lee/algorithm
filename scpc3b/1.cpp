#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <queue>

using namespace std;

int N, M;
vector<int> e[20001];
typedef pair<vector<int>, int> State;
State finish;

vector<State> getAdj(State s)
{
	vector<State> ret;

	int zero = s.second;
	for(int i=0; i<e[zero].size(); i++) {
		State a = s;
		int next = e[zero][i];
		swap(a.first[zero], a.first[next]);
		a.second = next;
		ret.push_back(a);
	}

	return ret;
}

int h(State s)
{
	int ret = 0;
	for(int i=1; i<=N; i++) {
		if( s.first[i] != finish.first[i] )
			ret++;
	}
	return ret;
}

int best;
void dfs(State here, int steps)
{
	if( steps + h(here) >= best )
		return;
	if( here == finish ) {
		best = steps;
		return;
	}

	vector<State> adj = getAdj(here);
	for(int i=0; i<adj.size(); i++)
		dfs(adj[i], steps+1);
}

int ids(State start, int growthStep)
{
	for(int limit=4; ; limit += growthStep) {
		best = limit+1;
		dfs(start, 0);
		if( best <= limit )
			return best;
	}
	return -1;
}
int main(void)
{
	setbuf(stdout, NULL);
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		for(int i=0; i<20001; i++)
			e[i].clear();

		scanf("%d %d", &N, &M);
		for(int i=0; i<M; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			e[a].push_back(b);
			e[b].push_back(a);
		}

		vector<int> p(N+1, 0);
		int zero;

		for(int i=1; i<=N; i++) {
			scanf("%d", &p[i]);
			if( p[i] == 0 )
				zero = i;
		}
		State first = make_pair(p, zero);

		for(int i=1; i<=N; i++) {
			scanf("%d", &p[i]);
			if( p[i] == 0 )
				zero = i;
		}
		finish = make_pair(p, zero);

		int ret = ids(first, 100);
		printf("Case #%d\n%d\n", test+1, ret);
	}
	return 0;
}