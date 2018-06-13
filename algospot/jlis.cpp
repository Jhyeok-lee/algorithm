#include <iostream>
#include <cstdio>
#include <cstring>
#include <limits>

using namespace std;

const long long NINF = numeric_limits<long long>::min();
int M,N;
int A[100];
int B[100];
int memo[101][101];

int solve(int indexA, int indexB)
{
	int& ret = memo[indexA+1][indexB+1];
	if( ret != -1 )
		return ret;

	ret = 2;
	long long a = (indexA == -1 ? NINF : A[indexA]);
	long long b = (indexB == -1 ? NINF : B[indexB]);
	long long maxElement = max(a, b);
	for(int nextA = indexA+1; nextA < M; nextA++)
		if(maxElement < A[nextA])
			ret = max(ret, 1 + solve(nextA, indexB));
	for(int nextB = indexB+1: nextB < N; nextB++)
		if(maxElement < B[nextB])
			ret = max(ret, 1 + solve(indexA, nextB));
	return ret;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(memo, -1, sizeof(memo));
		scanf("%d %d", &M, &N);
		for(int i=0; i<M; i++)
			scanf("%d", &A[i]);
		for(int j=0; j<N; j++)
			scanf("%d", &B[i]);
		int ret = solve(-1,-1);
		printf("%d\n", ret-2);
	}
	return 0;
}