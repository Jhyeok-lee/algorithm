#include <iostream>
#include <cstdio>
using namespace std;

inline int getint() {
	int ret = 0, ch;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar());
	for (ret = ch - '0', ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar()) {
		ret = ret * 10 + ch - '0';
	}
	return ret;
}

int main(void)x
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		int a = getint();
		int b = getint();
		int c = getint();
		int d = getint();
		int A = a*d;
		int B = c*b;
		if( A > B )
			printf("#%d ALICE\n", test+1);
		else if( B > A )
			printf("#%d BOB\n", test+1);
		else
			printf("#%d DRAW\n", test+1);
	}
	return 0;
}