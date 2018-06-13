#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		int n;
		long long s;
		scanf("%d", &n);
		long long ret = 0;
		for(int i=0; i<n; i++) {
			scanf("%lld", &s);
			long long p = s%10;
			long long a = s/10;
			ret += (long long)pow(a, p);
		}
		printf("#%d %lld\n", test+1, ret);
	}
}