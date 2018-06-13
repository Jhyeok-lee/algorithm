#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		int D, H, M;
		scanf("%d %d %d", &D, &H, &M);
		int a = 11*24*60 + 11*60 + 11;
		int b = D*24*60 + H*60 + M;
		if( b - a >= 0 )
			printf("#%d %d\n", test+1, b-a);
		else
			printf("#%d -1\n", test+1);
	}
	return 0;
}