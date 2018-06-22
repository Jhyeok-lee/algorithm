#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define INF 1234567890

int N, M, K;
int a[1001][1001];
int tree[4000][4000];

int initB(int nodeA, int alo, int ahi, int nodeB, int blo, int bhi)
{
	if( blo > bhi )
		return INF;
	if( blo == bhi )
		return tree[nodeA][nodeB] = a[alo][blo];
	int mid = (blo+bhi)/2;
	int left = initB(nodeA, alo, ahi, nodeB*2, blo, mid);
	int right = initB(nodeA, alo, ahi, nodeB*2+1, mid+1, bhi);
	return tree[nodeA][nodeB] = min(left, right);
}

int initA(int nodeA, int alo, int ahi, int nodeB, int blo, int bhi)
{
	if( alo > ahi )
		return INF;
	if( alo == ahi )
		return tree[nodeA][nodeB] = initB(nodeA, alo, ahi, nodeB, blo, bhi);

	int mid = (alo+ahi)/2;
	int left = initA(nodeA*2, alo, mid, nodeB, blo, bhi);
	int right = initA(nodeA*2+1, mid+1, ahi, nodeB, blo, bhi);
	return tree[nodeA][nodeB] = min(left, right);
}

void updateB(int nodeA, int alo, int ahi,
			int nodeB, int blo, int bhi,
			int a, int b, int p)
{
	if( blo > bhi )
		return;
	if( b < blo || bhi < b )
		return;
	if( blo == bhi ) {
		tree[nodeA][nodeB] += p;
		return;
	}
	int mid = (blo+bhi)/2;
	updateB(nodeA, alo, ahi, nodeB*2, blo, mid, a, b, p);
	updateB(nodeA, alo, ahi, nodeB*2+1, mid+1, bhi, a, b, p);
	tree[nodeA][nodeB] = min(tree[nodeA][nodeB*2], tree[nodeA][nodeB*2+1]);
}

void updateA(int nodeA, int alo, int ahi,
			int nodeB, int blo, int bhi,
			int a, int b, int p)
{
	if( alo > ahi )
		return;
	if( a < alo || ahi < a )
		return;
	if( alo == ahi ) {
		updateB(nodeA, alo, ahi, nodeB, blo, bhi, a, b, p);
		return;
	}
	int mid = (alo+ahi)/2;
	updateA(nodeA*2, alo, mid, nodeB, blo, bhi, a, b, p);
	updateA(nodeA*2, mid+1, ahi, nodeB, blo, bhi, a, b, p);
	tree[nodeA][nodeB] = min(tree[nodeA*2][nodeB], tree[nodeA*2+1][nodeB]);
}

int queryB(int nodeA, int alo, int ahi,
			int nodeB, int blo, int bhi,
				int xlo, int xhi, int ylo, int yhi)
{
	if( blo > bhi )
		return INF;
	if( yhi < blo || bhi < ylo )
		return INF;
	if( ylo <= blo && bhi <= yhi ) {
		printf("fuck %d %d %d %d : %d\n", alo, ahi, blo, bhi, tree[nodeA][nodeB]);
		printf("fuck %d %d\n", nodeA, nodeB);
		return tree[nodeA][nodeB];
	}
	
	int mid = (blo+bhi)/2;
	int left = queryB(nodeA, alo, ahi, nodeB*2, blo, mid,
			xlo, xhi, ylo, yhi);
	int right = queryB(nodeA, alo, ahi, nodeB*2+1, mid+1, bhi,
			xlo, xhi, ylo, yhi);
	return min(left, right);
}

int queryA(int nodeA, int alo, int ahi,
			int nodeB, int blo, int bhi,
				int xlo, int xhi, int ylo, int yhi)
{
	if( alo > ahi )
		return INF;
	if( xhi < alo || ahi < xlo )
		return INF;
	if( xlo <= alo && ahi <= xhi )
		return queryB(nodeA, alo, ahi, nodeB, blo, bhi,
			xlo, xhi, ylo, yhi);
	
	int mid = (alo+ahi)/2;
	int left = queryA(nodeA*2, alo, mid, nodeB, blo, bhi,
			xlo, xhi, ylo, yhi);
	int right = queryA(nodeA*2+1, mid+1, ahi, nodeB, blo, bhi,
			xlo, xhi, ylo, yhi);
	return min(left, right);
}

int main(void)
{
	setbuf(stdout,NULL);
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(a, 0, sizeof(a));
		memset(tree, 0, sizeof(tree));
		scanf("%d %d %d", &N, &M, &K);
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++)
				scanf("%d", &a[i][j]);
		}
		initA(1,0,N-1,1,0,N-1);
		int ret = 0;
		for(int i=0; i<M; i++) {
			for(int j=0; j<K; j++) {
				int x,y,p;
				scanf("%d %d %d",&x,&y,&p);
				x--, y--;
				updateA(1,0,N-1,1,0,N-1,x,y,p);
			}
			int r1,c1,r2,c2;
			scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
			r1--, c1--, r2--, c2--;
			ret += queryA(1,0,N-1,1,0,N-1,r1,r2,c1,c2);
			printf("%d\n", ret);
		}
		printf("#%d %d\n", test+1, ret);
	}
}