#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 1000000009

int N,K,L;
long long dp[50001][101];
long long sum[50001];
bool mine[50001];

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(dp, 0, sizeof(dp));
		memset(mine, 0, sizeof(mine));
		memset(sum, 0, sizeof(sum));
		scanf("%d %d %d", &N, &K, &L);
		for(int i=0; i<L; i++) {
			int pos;
			scanf("%d", &pos);
			mine[pos] = 1;
		}

		sum[N] = 1;
		dp[N][0] = 1;

		for(int i=N; i>=0; i--) {
			for(int k=1; k<=K; k++) {
				if( i-k>=0 && !mine[i-k] ) {
					dp[i-k][k] = (sum[i] - dp[i][k] + MOD) % MOD;
					sum[i-k] = (sum[i-k] + dp[i-k][k]) % MOD;
				}
			}
		}

		printf("Case #%d\n%lld\n", test+1, sum[0]);
	}
	return 0;
}