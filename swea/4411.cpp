#include <iostream>

using namespace std;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		long long N, K;
		scanf("%lld %lld", &N, &K);
		long long ret = 1;
		K++;
		if( K == 1 )
			ret = N;
		else {
			for(long long i=2; i<=N; i++)
				ret = (ret+K-1)%i+1;
		}
		printf("#%d %lld\n", test+1, ret);
	}
	return 0;
}