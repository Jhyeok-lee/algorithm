#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 1000000007

int N;
int A[100000];
int B[100000];
long long memo[100000][4];

long long solve(int idx, int c)
{
	if( idx == N-1 ) {
		if( c == 0 )
			return A[idx];
		else if( c == 1 )
			return B[idx-1];
		else if( c == 2 )
			return B[idx];
		return 0;
	}
	if( idx >= N )
		return 0;
	long long& ret = memo[idx][c];
	if( ret != -1 )
		return ret;

	ret = 0;
	if( c == 0 ) {
		ret = (ret + (A[idx] * solve(idx+1, 0) % MOD)) %MOD;
		ret = (ret + (A[idx] * solve(idx+1, 1) % MOD)) %MOD;
		ret = (ret + (A[idx] * solve(idx+1, 2) % MOD)) %MOD;
		ret = (ret + (A[idx] * solve(idx+1, 3) % MOD)) %MOD;
	}
	else if( c == 1 && idx-1 >= 0 ) {
		ret = (ret + (B[idx-1] * solve(idx+1, 0) % MOD )) %MOD;
		ret = (ret + (B[idx-1] * solve(idx+1, 1) % MOD )) %MOD;
		ret = (ret + (B[idx-1] * solve(idx+1, 2) % MOD )) %MOD;
		ret = (ret + (B[idx-1] * solve(idx+1, 3) % MOD )) %MOD;
	}
	else if( c == 2 && idx < N-1 ) {
		ret = (ret + (B[idx] * solve(idx+1, 0) % MOD )) %MOD;
		ret = (ret + (B[idx] * solve(idx+1, 2) % MOD )) %MOD;
		ret = (ret + (B[idx] * solve(idx+1, 3) % MOD )) %MOD;
	}
	else if( c == 3 && idx+1 < N-1 && idx+3 < N ) {
		ret = (ret + ((B[idx+1]*(B[idx+1]-1)) %MOD
			* solve(idx+3, 0) % MOD )) %MOD;
		ret = (ret + ((B[idx+1]*(B[idx+1]-1)) %MOD
			* solve(idx+3, 1) % MOD )) %MOD;
		ret = (ret + ((B[idx+1]*(B[idx+1]-1)) %MOD
			* solve(idx+3, 2) % MOD )) %MOD;
		ret = (ret + ((B[idx+1]*(B[idx+1]-1)) %MOD
			* solve(idx+3, 3) % MOD )) %MOD;
	}

	return ret;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		memset(memo, 0, sizeof(memo));
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d", &A[i]);
		for(int i=0; i<N-1; i++)
			scanf("%d", &B[i]);

		for(int i=0; i<N; i++)
			memo[i][0] = A[i];
		memo[0][0] = 0;
		for(int i=1; i<N; i++)
			memo[i][1] = B[i-1];
		for(int i=0; i<N-1; i++)
			memo[i][2] = B[i];
		memo[N-1] = 0;
		memo[N-2] = 0;
		for(int i=0; i<N-2; i++)
			memo[i][3] = B[i+1];

		

		long long ret = 0;
		for(int i=0; i<4; i++)
			ret = (ret + solve(0,i)) %MOD;
		printf("#%d %lld\n", test+1, ret);
	}
}