#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_N 100

int N;
int board[MAX_N][MAX_N];
int cache[MAX_N][MAX_N];

int solve(int i, int j)
{
	if( i < 0 || i >= N )
		return 0;
	if( j < 0 || j >= N )
		return 0;
	if( i == N-1 && j == N-1 )
		return 1;

	int& ret = cache[i][j];
	if( ret ! = -1 )
		return ret;

	int dist = board[i][j];
	return ret = solve(i+dist,j) || solve(i,j+dist);
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(board, 0, sizeof(board));
		memset(cache, -1, sizeof(cache));
		scanf("%d", &N);
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++)
				scanf("%d", &board[i][j]);
		}
		int ret = solve(0,0);
		if( ret )
			printf("YES\n");
		else
			printf("NO\n");
	}
}