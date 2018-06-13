#include <iostream>

using namespace std;

int N, K;
int arr[100001];

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		scanf("%d %d", &N, &K);
		for(int i=0; i<N; i++)
			scanf("%d", &arr[i]);
		arr[N] = 0;

		int lo = 0, hi = 0;
		int a,b,c,d;
		int ret = 0;
		bool p = true;
		int last;
		while( 1 ) {
			if( arr[hi] < arr[hi+1] )
				hi++;
			else if( p ) {
				p = false;
				a = lo, b = hi;
				hi++;
				lo = hi;
			}
			else {
				int len;
				c = lo, d = hi;
				if( arr[b] < arr[c+1] ) {
					len = (b-a+1) + (d-c+1);
				}
				else
					len = (b-a+2);
				
				if( len >= K )
					ret += (len-K+1)*(len-K+2)/2;
				a = c;
				b = d;
				hi++;
				lo = hi;
			}
			if( lo == N )
				break;
		}

		printf("#%d %d\n", test+1, ret);
	}
	return 0;
}