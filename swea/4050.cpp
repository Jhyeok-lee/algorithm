#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
long long price[100000];

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(price, 0, sizeof(price));
		scanf("%d", &N);
		long long ret = 0;
		for(int i=0; i<N; i++) {
			scanf("%lld", &price[i]);
			ret += price[i];
		}
		sort(price, price+N);
		for(int i=N-3; i>=0; i-=3)
			ret -= price[i];
		
		printf("#%d %lld\n", test+1, ret);
	}
}