#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

bool isPrime[1000001];
int count[1000001];

void precalc(void)
{
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = false;
	isPrime[1] = true;
	for(int i=2; i<=1000; i++) {
		if( !isPrime[i] )
			continue;
		for(int j=i*i; j<=1000000; j+=i)
			isPrime[j] = false;
	}

	count[2] = 1;
	for(int i=3; i<=1000000; i++) {
		count[i] = count[i-1];
		if( isPrime[i] && i%4==1 )
			count[i]++;
	}
}

int main(void)
{
	precalc();
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		int L, R;
		scanf("%d %d", &L, &R);
		int ret = count[R] - count[L-1];
		printf("#%d %d\n", test+1, ret);
	}
	return 0;
}