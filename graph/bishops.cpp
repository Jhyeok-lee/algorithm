#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int dx[2] = {-1,1};
const int dy[2] = {1,1};
vector<string> board;
int id[2][8][8];
int n,m;
int adj[64][64];
vector<int> aMatch, bMatch;
vector<bool> visited;

bool dfs(int a)
{
	if(visited[a])
		return false;
	visited[a] = true;
	for(int b=0; b<m; b++) {
		if(adj[a][b]) {
			if(bMatch[b] == -1 || dfs(bMatch[b])) {
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
		}
	}
	return false;
}

int bipartiteMatch()
{
	aMatch = vector<int>(n,-1);
	bMatch = vector<int>(m,-1);
	int size = 0 ;
	for(int start=0; start<n; start++) {
		visited = vector<bool>(n,false);
		if(dfs(start))
			size++;
	}
	return size;
}

int placeBishops()
{
	memset(id, -1, sizeof(id));
	int count[2] = {0,0};
	for(int dir=0; dir<2; dir++) {
		for(int y=0; y<board.size(); y++) {
			for(int x=0; x<board.size(); x++) {
				if(board[y][x] == '.' && id[dir][y][x] == -1) {
					int cy = y;
					int cx = x;
					while( cy >= 0 && cy < board.size() &&
						cx >= 0 && cx < board.size() &&
						board[cy][cx] == '.' ) {
						id[dir][cy][cx] = count[dir];
						cy += dy[dir];
						cx += dx[dir];
					}
					count[dir]++;
				}
			}
		}
	}

	n = count[0];
	m = count[1];
	memset(adj, 0, sizeof(adj));
	for(int y=0; y<board.size(); y++) {
		for(int x=0; x<board.size(); x++) {
			if( board[y][x] == '.' )
				adj[id[0][y][x]][id[1][y][x]] = 1;
		}
	}
	return bipartiteMatch();
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		int N;
		board.clear();
		scanf("%d", &N);
		for(int i=0; i<N; i++) {
			string s;
			cin >> s;
			board.push_back(s);
		}
		int ret = placeBishops();
		printf("%d\n", ret);
	}
}