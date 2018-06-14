#include <iostream>
#include <cstdio>

using namespace std;

unsigned long long M[64];

int countN(unsigned long long n)
{
	int ret = 0;
	while( n != 1 ) {
		if( n%2 == 0 )
			n /= 2;
		else
			n = 3*n+1;
		ret++;
	}
	return ret;
}

void init(void)
{
	M[0] = 1;
	M[1] = 2;
	for(int i=2; i<64; i++)
		M[i] = M[i-1]*2;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	init();
	for(int test=0; test<Case; test++) {
		int K;
		scanf("%d", &K);
		unsigned long long m = 1;
		while(1) {
			int k = countN(m);
			if( k == K )
				break;
			m++;
		}
		printf("Case #%d\n%llu %llu\n", test+1, m, M[K]);
	}
}