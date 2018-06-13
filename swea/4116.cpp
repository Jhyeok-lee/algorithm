#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define MOD 1000000007

const int M[4][4] = 
{
	{-1,0,1,0},
	{-1,0,0,1},
	{0,-1,1,0},
	{0,-1,0,1}
};
int N;
vector<string> board;
int memo[500][500];

bool check(int a, int b, int c , int d)
{
	if( a < 0 || a >= N )
		return false;
	if( b < 0 || b >= N )
		return false;
	if( c < 0 || c >= N )
		return false;
	if( d < 0 || d >= N )
		return false;
	if( board[a][b] != board[c][d] )
		return false;
	return true;
}

int solve(int a, int b, int c, int d)
{
	if( a == 0 && b == 0 && c == N-1 && d == N-1 )
		return 1;

	int& left = memo[a][b];
	if( left != -1 )
		return left;
	int &right = memo[c][d];
	if( right != -1 )
		return right;

	left = 0;
	right = 0;
	for(int i=0; i<4; i++) {
		int nextA = a + M[i][0];
		int nextB = b + M[i][1];
		int nextC = c + M[i][2];
		int nextD = d + M[i][3];
		if( check(nextA,nextB,nextC,nextD) ) {
			left += solve(nextA,nextB,nextC,nextD);
			right += solve(nextA,nextB,nextC,nextD);
		}
	}
	return left;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(memo, -1, sizeof(memo));
		board.clear();
		scanf("%d", &N);
		board = vector<string>(N);
		for(int i=0; i<N; i++)
			cin >> board[i];

		if( board[0][0] != board[N-1][N-1] ) {
			printf("#%d 0\n", test+1);
			continue;
		}
		int ret = 0;
		for(int i=0; i<N; i++)
			ret += solve(i, N-1-i, i, N-1-i);

		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++)
				printf("%d ", memo[i][j]);
			printf("\n");
		}
		
		printf("#%d %d\n", test+1, ret);
	}
}