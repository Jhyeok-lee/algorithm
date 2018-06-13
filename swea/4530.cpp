#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

unsigned long long comb[13][13];
unsigned long long fac[13];

void init(void)
{
	fac[0] = 1;
	fac[1] = 1;
	for(int i=2; i<13; i++)
		fac[i] = fac[i-1] * i;

	for(int n=0; n<13; n++) {
		for(int k=0; k<=n; k++) {
			comb[n][k] = fac[n]/fac[k];
			comb[n][k] /= fac[n-k];
		}
	}
}

long long solve1(long long n, long long prev)
{
	int len = 0;
	long long N = n;
	long long ret = 0;
	while( N / 10 != 0 ) {
		len++;
		N /= 10;
	}

	int b = 1;
	for(int i=1; i<=len; i++) {
		ret += comb[len][i] * pow(10,len-i) * b;
		b *= -1;
	}

	if( N < 4 )
		ret *= N;
	else if( N == 4 ) {
		ret *= (N-1);
		ret += prev+1;
	}
	else {
		ret *= (N-1);
		ret += pow(10,len);
	}

	//printf("%d %lld\n", n, ret);
	return ret;
}

long long solve(long long n)
{
	long long ret = 0;
	long long count = 0;
	long long prev = 0;
	while( n != 0 ) {
		long long r = n%10;
		r *= pow(10,count);
		ret += solve1(r, prev);
		prev += r;
		count++;
		n /= 10;
	}
	return ret;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	init();
	for(int test=0; test<Case; test++) {
		long long A, B;
		scanf("%lld %lld", &A, &B);
		long long aCount = solve(abs(A));
		long long bCount = solve(abs(B));
		long long ret = 0;
		if( A < 0 && B > 0 )
			ret = abs(A) + abs(B) - aCount - bCount -1;
		else if( A > 0 && B > 0 )
			ret = abs(B) - abs(A) - (bCount - aCount);
		else
			ret = abs(A) - abs(B) - (aCount - bCount);
		
		printf("#%d %lld\n", test+1, ret);
	}
	return 0;
}