#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 1000000007

int N;
long long A[100002];
long long B[100002];
long long dp[100002][4];

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		memset(dp, 0, sizeof(dp));
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%lld", &A[i]);
		for(int i=0; i<N-1; i++)
			scanf("%lld", &B[i]);

		dp[0][0] = A[0];
		dp[0][1] = 0;
		dp[0][2] = B[0];
		dp[0][3] = B[1];
		for(int i=1; i<N; i++) {
			long long sum = 0;
			sum = (sum + dp[i-1][0] * A[i] % MOD) % MOD;
			sum = (sum + dp[i-1][1] * A[i] % MOD) % MOD;
			sum = (sum + dp[i-1][2] * A[i] % MOD) % MOD;
			if( i-3 >= 0)
				sum = (sum + dp[i-3][3] * A[i] % MOD) % MOD;
			dp[i][0] = sum % MOD;

			sum = dp[i-1][0] * B[i-1] % MOD;
			sum = (sum + dp[i-1][1] * B[i-1] % MOD) % MOD;
			if( i-3 >= 0)
				sum = (sum + dp[i-3][3] * B[i-1] % MOD) % MOD;
			dp[i][1] = sum;

			sum = dp[i-1][0] * B[i] % MOD;
			sum = (sum + dp[i-1][1] * B[i] % MOD) % MOD;
			sum = (sum + dp[i-1][2] * B[i] % MOD) % MOD;
			if( i-3 >= 0)
				sum = (sum + dp[i-3][3] * B[i] % MOD) % MOD;
			dp[i][2] = sum;

			const long long a = 1e20;
			long long jump = B[i+1]*(B[i+1]-1) % MOD;
			sum = dp[i-1][0] * jump % MOD;
			sum = (sum + dp[i-1][1]*jump % MOD) % MOD;
			sum = (sum + dp[i-1][2]*jump % MOD) % MOD;
			if( i-3 >= 0)
				sum = (sum + dp[i-3][3]*jump % MOD) % MOD;
			dp[i][3] = sum;
		}
		
		long long ret = 0;
		for(int i=0; i<4; i++)
			ret = (ret + dp[N-1][i]) % MOD;
		printf("#%d %lld\n", test+1, ret);
	}
}