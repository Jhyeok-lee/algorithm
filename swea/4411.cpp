#include <iostream>

using namespace std;

long long solve(long long n, long long k)
{
	if( n == 1 )
		return 1;
	return (solve(n-1,k) + k-1)%n+1;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		long long N, K;
		scanf("%lld %lld ", &N, &K);
		long long ret = solve(N,(K+1)%N);
		printf("#%d %lld\n", test+1, ret);
	}
}