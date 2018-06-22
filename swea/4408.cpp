#include <iostream>

using namespace std;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		int N;
		scanf("%d", &N);
		int t[401] = {0,};
		for(int i=0; i<N; i++) {
			int a,b;
			scanf("%d %d", &a, &b);
			if( a > b )
				swap(a,b);
			if( a%2 == 0 )
				a--;
			if( b%2 == 1 )
				b++;
			for(int j=a; j<=b; j++)
				t[j]++;
		}

		int ret = 0;
		for(int i=1; i<401; i++)
			ret = max(ret, t[i]);
		printf("#%d %d\n", test+1, ret);
	}
	return 0;
}