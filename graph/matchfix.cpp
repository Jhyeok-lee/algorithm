#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1234567890;
int V;
int capacity[200][200];
int flow[200][200];

int networkFlow(int source, int sink)
{
	int totalFlow = 0;
	while( true ) {
		vector<int> parent(V, -1);
		queue<int> q;
		parent[source] = source;
		q.push(source);
		while( !q.empty() && parent[sink] == -1 ) {
			int here = q.front();
			q.pop();
			for(int there=0; there<V; there++) {
				if( capacity[here][there] - flow[here][there] > 0 &&
					parent[there] == -1 ) {
					q.push(there);
					parent[there] = here;
				}
			}
		}
		if( parent[sink] == -1 )
			break;
		int amount = INF;
		for(int p=sink; p != source; p=parent[p])
			amount = min(amount,
				capacity[parent[p]][p] - flow[parent[p]][p]);
		for(int p=sink; p != source; p=parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		totalFlow += amount;
	}
	return totalFlow;
}

int N,M;
int win[12];
int match[100][2];

int canWinWith(int totalWins, int prevFlow)
{
	if(*max_element(win+1, win+N) >= totalWins)
		return false;

	memset(capacity, 0, sizeof(capacity));
	V = 2 + M + N;
	for(int i=0; i<M; i++) {
		capacity[0][2+i] = 1;
		for(int j=0; j<2; j++)
			capacity[2+i][2+M+match[i][j]] = 1;
	}

	for(int i=0; i<N; i++) {
		int maxWin = (i==0 ? totalWins : totalWins-1);
		capacity[2+M+i][1] = maxWin - win[i];
	}

	int flow = networkFlow(0,1);
	return flow + prevFlow;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(capacity, 0, sizeof(capacity));
		memset(flow, 0, sizeof(flow));
		scanf("%d %d", &N, &M);
		for(int i=0; i<N; i++)
			scanf("%d", &win[i]);
		int count = 0;
		for(int i=0; i<M; i++) {
			scanf("%d %d", &match[i][0], &match[i][1]);
			if( match[i][0] == 0 || match[i][1] == 0 )
				count++;
		}
		int ret = -1;
		int prev = 0;
		for(int i=win[0]; i<win[0]+count+1 ;i++) {
			int flow = canWinWith(i, prev);
			prev = flow;
			if( flow == M ) {
				ret = i;
				break;
			}
		}
		printf("%d\n", ret);
	}
}