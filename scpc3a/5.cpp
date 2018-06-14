#include <iostream>
#include <cstdio>

using namespace std;

int N;
char s[1000001];
char a[1000001];

void hanoi(int n, int from, int to, int by)
{
	if( n == 1 ) {
		printf("%d : %c -> %c\n",n, from+'A', by+'A');
		printf("%d : %c -> %c\n",n, by+'A', to+'A');
		return;
	}
	hanoi(n-1, from, by, to);
	printf("%d : %c -> %c\n",n,from+'A', by+'A');
	printf("%d : %c -> %c\n",n,by+'A', to+'A');
	hanoi(n-1, to, from, by);
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		scanf("%d %s", &N, s);
		for(int i=0; i<N; i++)
			a[i] = 'A';
		a[N] = '\0';
		hanoi(N-1,0,2,1);
		hanoi(N-1,2,1,0);
		printf("Case #%d\n", test+1);
	}
	return 0;
}