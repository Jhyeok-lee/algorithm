#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MOVE[4][2] = {
	{-1, 0}, {1, 0}, {0, -1}, {0, 1}
};
const int P[2][2] = {
	{1, 0}, {0, 1}
};

class State {
public:
	int r, c, sum;
	vector<vector<bool> > visited;
};
int N, M;
vector<string> board;

int search()
{
	int ret = 1234567890;
	queue<State> q;
	vector<vector<bool> > v(N, vector<bool>(M, false));
	State start;
	start.r = 0;
	start.c = 0;
	start.visited = v;
	q.push(start);
	while( !q.empty() ) {
		int r = q.front().r;
		int c = q.front().c;
		int sum = q.front().sum;
		vector<vector<bool> > visited = q.front().visited;
		q.pop();

		printf("%d %d\n", r,c);

		if( sum > ret )
			continue;

		if( r == N-1 && c == M-1 ) {
			ret = min(ret, sum);
			continue;
		}

		int A,B,C = 0;
		for(int i=0; i<4; i++) {
			int a = r + MOVE[i][0];
			int b = c + MOVE[i][1];
			if( a < 0 || b < 0 )
				continue;
			if( a > N || b > M )
				continue;
			if( visited[a][b] )
				continue;
			if( !board[a][b] )
				continue;
			if( C > board[a][b] ) {
				A = a;
				B = b;
				C = board[a][b];
			}
		}

		int nextSum = sum;
		if( !visited[r][c] && board[r][c] ) {
			nextSum += board[r][c];
			visited[r][c] = 1;
		}
		for(int i=0; i<4; i++) {
			int a = r + MOVE[i][0];
			int b = c + MOVE[i][1];
			if( a < 0 || b < 0 )
				continue;
			if( a > N || b > M )
				continue;
			if( visited[a][b] )
				continue;
			if( !board[a][b] )
				continue;
			if( a == A && b == B )
				continue;
			sum += board[a][b];
			visited[a][b] = 1;
		}

		for(int i=0; i<2; i++) {
			int nextR = r + P[i][0];
			int nextC = c + P[i][1];
			if( nextR < N || nextC < M ) {
				State next;
				next.r = nextR;
				next.c = nextC;
				next.sum = nextSum;
				next.visited = visited;
				q.push(next);
			}
		}
	}
	return ret;
}

int main(void)
{
	//setbuf(stdout, NULL);
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		scanf("%d %d", &N, &M);
		board = vector<string>(N);
		for(int i=0; i<N; i++)
			cin >> board[i];

		int ret = search();
		printf("#%d %d\n", test+1, ret);
	}
}