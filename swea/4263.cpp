#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define M 1000000007

int N;
long long L[1000];
long long D[1000];
long long memo[100001];

long long P(long long n)
{
	n %= (M-1);
	if( n <= 100000 )
		return memo[n];
	return (P(n-100000) * P(100000))%M;
}

void init(void)
{
	memo[0] = 1;
	memo[1] = 26;
	for(int i=1; i<=100000; i++)
		memo[i] = (memo[i-1] * 26)%M;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	init();
	for(int test=0; test<Case; test++) {
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%lld", &L[i]);
		sort(L, L+N);
		long long ret = P(L[0]);
		for(int i=1; i<N-1; i++) {
			long long p = (L[i+1] + L[i-1] - L[i]*2);
			long long d = L[i] - L[i-1];
			if( p > 0 )
				ret = (ret * P((d+1)/2))%M;
			else
				ret = (ret * P((d+1)/2+(p-1)/2))%M;
		}
		long long d = L[N-1] - L[N-2];
		ret = (ret * P( (d+1)/2 ) )%M;
		printf("#%d %lld\n", test+1, ret);
	}
}