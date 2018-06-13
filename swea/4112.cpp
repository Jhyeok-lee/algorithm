#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if( a > b )
			swap(a,b);
		int aline = 1;
		while( a <= aline*(aline-1)/2 || a > aline*(aline+1)/2 )
			aline++;
		int bline = 1;
		while( b <= bline*(bline-1)/2 || b > bline*(bline+1)/2 )
			bline++;

		int ret = 0;
		while( aline != bline ) { 
			a += aline+1;
			aline++;
			ret++;
		}
		if( b > a )
			ret += b-a;
		if( b < a-ret )
			ret += (a-ret)-b;
		printf("#%d %d\n", test+1, ret);
	}
	return 0;
}