#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int N;
int ret;

bool check(int r, int c, vector<vector<int> >& board)
{
	for(int i=1; i<N; i++) {
		if( r-i < 0 || c-i < 0 )
			break;
		if( board[r-i][c-i] == 2 )
			break;
		if( !board[r-i][c-i] )
			return false;
	}
	for(int i=1; i<N; i++) {
		if( r+i >= N || c+i >= N )
			break;
		if( board[r+i][c+i] == 2 )
			break;
		if( !board[r+i][c+i] )
			return false;
	}
	for(int i=1; i<N; i++) {
		if( r+i >= N || c-i < 0 )
			break;
		if( board[r+i][c-i] == 2 )
			break;
		if( !board[r+i][c-i] )
			return false;
	}
	for(int i=1; i<N; i++) {
		if( r-i >= N || c+i < 0 )
			break;
		if( board[r-i][c+i] == 2 )
			break;
		if( !board[r-i][c+i] )
			return false;
	}

	return true;
}

void search(int row, int sum, vector<vector<int> >& board)
{
	if( row == N ) {
		ret = max(ret, sum);
		return;
	}
	
	for(int col=0; col<N; col++) {
		if( board[row][col] == 1 && check(row, col, board) ) {
			vector<vector<int> > nextBoard(board);
			int nextSum = sum;
			for(int i=col; i<N; i++) {
				if( nextBoard[row][i] == 1 ) {
					nextBoard[row][i] = 0;
					nextSum++;
				}
			}
			search(row+1, nextSum, nextBoard);
		}
	}
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		scanf("%d", &N);
		vector<vector<int> > board(N, vector<int>(N,0));
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				char c;
				scanf("%c", &c);
				if( c == '.' )
					board[i][j] = 1;
				if( c == '*' )
					board[i][j] = 2;
			}
		}
		ret = 0;
		search(0, 0, board);
		printf("%d\n", ret);
	}
}