#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
	while( b != 0 ) {
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a,b);
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		int N;
		int s[5] = {0,};
		int l[5] = {0,};
		int d[5] = {0,};
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d %d %d", &s[i], &l[i], &d[i]);
		int a[5] = {0,};
		for(int i=0; i<N; i++) {
			int start = l[i] - d[i];
			while( start % s[i] != 0 )
				start += l[i];
			a[i] = start/s[i];
			printf("%d\n", a[i]);
		}
		int ret = a[0];
		for(int i=1; i<N; i++)
			ret = lcm(ret, a[i]);
		printf("Case #%d\n%d\n", test+1, ret);
	}
	return 0;
}