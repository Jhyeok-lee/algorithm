#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define MOD 1000000007

int N;
bool check;
vector<bool> visited;
vector<int> nextColor[2];
vector<vector<int> > graph;
long long memo[100000][2];

bool isLeaf(int n)
{
	for(int i=0; i<graph[n].size(); i++) {
		int there = graph[n][i];
		if( !visited[there] )
			return false;
	}
	return true;
}

long long solve(int n, int color)
{
	if( isLeaf(n) )
		return 1;

	long long& ret = memo[n][color];
	if( ret != -1 )
		return ret;

	ret = 1;
	visited[n] = true;
	for(int i=0; i<graph[n].size(); i++) {
		int there = graph[n][i];
		if( !visited[there] ) {
			long long sum = 0;
			for(int j=0; j<nextColor[color].size(); j++) {
				int next = nextColor[color][j];	
				sum = (sum + solve(there, next) % MOD) % MOD;
			}
			ret = (ret * sum) % MOD;
		}
	}
	visited[n] = false;
	return ret % MOD;
}

int main(void)
{
	nextColor[0].push_back(1);
	nextColor[1].push_back(0);
	nextColor[1].push_back(1);
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(memo, -1, sizeof(memo));
		graph.clear();
		scanf("%d", &N);
		graph = vector<vector<int> >(N);
		for(int i=0; i<N-1; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			a--;
			b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		
		check = false;
		visited = vector<bool>(N,false);
		long long ret = solve(0,1) % MOD;
		ret = (ret + solve(0,0)) % MOD;
		printf("#%d %lld\n", test+1, ret);
	}
}