#include <iostream>
#include <cstdio>

using namespace std;

int N;
int F[16][16];

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		scanf("%d", &N);
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++)
				scanf("%d", &F[i][j]);
		}

		
	}
}