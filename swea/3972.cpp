#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

#define MAX_N 200

using namespace std;

int N;
int ret;
int dist[MAX_N][MAX_N];
map<pair<int, int>, int> visitedMemo;
map<vector<bool>, int> distMemo;

int calDist(vector<bool>& visited)
{
	if( distMemo.count(visited) > 0 )
		return distMemo[visited];

	int a = 0;
	for(int i=0; i<N-1; i++) {
		for(int j=i+1; j<N; j++) {
			if( visited[i] && visited[j] )
				a = max(a, dist[i][j]);
		}
	}
	int b = 0;
	for(int i=0; i<N-1; i++) {
		for(int j=i+1; j<N; j++) {
			if( !visited[i] && !visited[j] )
				b = max(b, dist[i][j]);
		}
	}

	vector<bool> t(visited);
	for(int i=0; i<N; i++) {
		if( t[i] )
			t[i] = false;
		else
			t[i] = true;
	}
	distMemo[visited] = a+b;
	distMemo[t] = a+b;
	return a+b;
}

void solve(int idx, vector<bool>& visited, int prevDist)
{
	if( idx == N )
		return;

	int value = calDist(visited);
	if( prevDist < value )
		return;
	ret = min(ret, value);
	pair<int, int> temp = make_pair(idx, value);
	if( visitedMemo.count(temp) > 0 )
		return;

	visited[idx] = true;
	value = calDist(visited);
	solve(idx+1, visited, value);
	visited[idx] = false;
	value = calDist(visited);
	solve(idx+1, visited, value);
	visitedMemo[temp] = 1;

	vector<bool> t(visited);
	for(int i=0; i<N; i++) {
		if( t[i] )
			t[i] = false;
		else
			t[i] = true;
	}
	value = calDist(t);
	temp = make_pair(idx, value);
	visitedMemo[temp] = 1;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		visitedMemo.clear();
		distMemo.clear();
		memset(dist, 0, sizeof(dist));
		scanf("%d", &N);
		for(int i=0; i<N-1; i++) {
			for(int j=i+1; j<N; j++) {
				scanf("%d", &dist[i][j]);
				dist[j][i] = dist[i][j];
			}
		}
		vector<bool> visited = vector<bool>(N, false);
		ret = 1234567890;
		solve(0, visited, 1234567890);
		printf("#%d %d\n", test+1, ret);
	}
}