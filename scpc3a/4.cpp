#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
	if( a < b )
		swap(a,b);
	if( b == 0 )
		return a;
	return gcd(b, a%b);
}

int lcm(int a, int b)
{
	return a*b/gcd(a,b);
}

int main(void)
{
	setbuf(stdout, NULL);
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
		int t[5] = {0,};
		for(int i=0; i<N; i++) {
			int temp = 1;
			while( (s[i]*temp+d[i])%l[i] != 0 )
				temp++;
			t[i] = temp;
		}
		int interval = t[0];
		for(int i=1; i<N; i++)
			interval = lcm(interval, t[i]);
		int ret = interval;
		while( true ) {
			bool check = true;
			for(int i=0; i<N; i++) {
				if( (s[i]*ret+d[i])%l[i] != 0 ) {
					check = false;
					break;
				}
			}
			if( !check )
				ret += interval;
			else
				break;
		}

		printf("Case #%d\n%d\n", test+1, ret);
	}
	return 0;
}