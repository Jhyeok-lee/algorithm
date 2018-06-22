#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		int N;
		scanf("%d", &N);
		int arr[5000] = {0,};
		for(int i=0; i<N; i++)
			scanf("%d", &arr[i]);
		int ret = 0;
		bool check[5000] = {false,};
		for(int i=1; i<N; i++) {
			if( check[i] )
				continue;
			int d = arr[i] - arr[0];
			check[i] = true;
			int next = arr[i] + d;
			ret++;
			for(int j=i+1; j<N; j++) {
				if( arr[j] == next ) {
					check[j] = true;
					next += d;
				}
			}
		}
		printf("#%d %d\n", test+1, ret);
	}
	return 0;
}