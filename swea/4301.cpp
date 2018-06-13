#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N, M;
bool board[1000][1000];

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(board, true, sizeof(board));
		scanf("%d %d", &N, &M);
		for(int i=0; i<M; i++) {
			for(int j=0; j<N; j++) {
				if( !board[i][j] )
					continue;
				if( i+2 < M )
					board[i+2][j] = false;
				if( j+2 < N )
					board[i][j+2] = false;
			}
		}
		int ret = 0;
		for(int i=0; i<M; i++) {
			for(int j=0; j<N; j++) {
				if( board[i][j] )
					ret++;
			}
		}
		printf("#%d %d\n", test+1, ret);
	}
	return 0;
}