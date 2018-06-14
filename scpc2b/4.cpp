#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int N,M;
int x[500];
int dp[500][500];
int dp2[500][500];

int cal(int lo, int hi)
{
	int& ret = dp2[lo][hi];
	if( ret != -1 )
		return ret;

	ret = 0;
	int mid = (lo+hi)/2;
	int v = x[mid];
	for(int i=lo; i<=hi; i++)
		ret += abs(v - x[i]);
	return ret;
}

int solve(int pos, int can)
{
	if( can == M-1 )
		return cal(pos, N-1);
	int& ret = dp[pos][can];
	if( ret != -1 )
		return ret;

	ret = 1234567890;
	for(int i=pos; i<N; i++)
		ret = min(ret, cal(pos,i) + solve(i+1, can+1));
	return ret;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(dp, -1, sizeof(dp));
		memset(dp2, -1, sizeof(dp2));
		scanf("%d %d", &N, &M);
		for(int i=0; i<N; i++)
			scanf("%d", &x[i]);
		sort(x, x+N);
		int ret = solve(0,0);
		printf("Case #%d\n%d\n", test+1, ret);
	}
}