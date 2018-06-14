#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
int A[10002];
int B[10002];
int dp[10002];

int solve(int idx)
{
	if( idx > N )
		return 0;

	int& ret = dp[idx];
	if( ret != -1 )
		return ret;

	ret = 0;
	ret = max(ret, A[idx] + solve(idx+1));
	ret = max(ret, B[idx+1] + solve(idx+2));
	return ret;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(dp, -1, sizeof(dp));
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		scanf("%d", &N);
		for(int i=1; i<=N; i++)
			scanf("%d", &A[i]);
		for(int i=1; i<=N; i++)
			scanf("%d", &B[i]);
		int ret = solve(0);
		
		printf("Case #%d\n%d\n", test+1, ret);
	}
}