#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define INF 1234567890

int N, M, K;
int a[1001][1001];
int tree[10000000];

int init(int node, int alo, int blo, int ahi, int bhi)
{
	if( alo > ahi )
		return INF;
	if( blo > bhi )
		return INF;
	if( alo == ahi && blo == bhi )
		return tree[node] = a[alo][blo];

	int one = init(node*4, alo, blo, (alo+ahi)/2, (blo+bhi)/2);
	int two = init(node*4+1, alo, (blo+bhi)/2+1, (alo+ahi)/2, bhi);
	int three = init(node*4+2, (alo+ahi)/2+1, blo, ahi, (blo+bhi)/2);
	int four =  init(node*4+3, (alo+ahi)/2+1, (blo+bhi)/2+1, ahi, bhi);
	one = min(one, two);
	one = min(one, three);
	one = min(one, four);
	return tree[node] = one;
}

void update(int node, int alo, int blo, int ahi, int bhi,
			int a, int b, int p)
{
	if( alo > ahi )
		return;
	if( blo > bhi )
		return;
	if( a < alo || ahi < a )
		return;
	if( b < blo || bhi < b)
		return;
	if( alo == ahi && blo == bhi ) {
		tree[node] += p;
		return;
	}

	update(node*4, alo, blo, (alo+ahi)/2, (blo+bhi)/2,a,b,p);
	update(node*4+1, alo, (blo+bhi)/2+1, (alo+ahi)/2, bhi,a,b,p);
	update(node*4+2, (alo+ahi)/2+1, blo, ahi, (blo+bhi)/2,a,b,p);
	update(node*4+3, (alo+ahi)/2+1, (blo+bhi)/2+1, ahi, bhi,a,b,p);
	tree[node] = min(tree[node], tree[node*4]);
	tree[node] = min(tree[node], tree[node*4+1]);
	tree[node] = min(tree[node], tree[node*4+2]);
	tree[node] = min(tree[node], tree[node*4+3]);
}

int query(int node, int alo, int blo, int ahi, int bhi,
				int xlo, int ylo, int xhi, int yhi)
{
	if( alo > ahi )
		return INF;
	if( blo > bhi )
		return INF;
	if( xhi < alo || ahi < xlo )
		return INF;
	if( yhi < blo || bhi < ylo)
		return INF;
	if( alo == ahi && blo == bhi )
		return tree[node];
	if( xlo <= alo && ahi <= xhi && 
		ylo <= blo && bhi <= yhi && ((ahi-alo+1)*(bhi-blo+1))%4 == 0) {
		return tree[node];
	}
	
	int one = query(node*4, alo, blo, (alo+ahi)/2, (blo+bhi)/2,
					xlo, ylo, xhi, yhi);
	int two = query(node*4+1, alo, (blo+bhi)/2+1, (alo+ahi)/2, bhi,
					xlo, ylo, xhi, yhi);
	int three = query(node*4+2, (alo+ahi)/2+1, blo, ahi, (blo+bhi)/2,
					xlo, ylo, xhi, yhi);
	int four = query(node*4+3, (alo+ahi)/2+1, (blo+bhi)/2+1, ahi, bhi,
					xlo, ylo, xhi, yhi);
	one = min(one, two);
	one = min(one, three);
	one = min(one, four);
	return one;
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
		init(1,0,0,N-1,N-1);
		int ret = 0;
		for(int i=0; i<M; i++) {
			for(int j=0; j<K; j++) {
				int x,y,p;
				scanf("%d %d %d",&x,&y,&p);
				x--, y--;
				update(1,0,0,N-1,N-1,x,y,p);
			}
			int r1,c1,r2,c2;
			scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
			r1--, c1--, r2--, c2--;
			ret += query(1,0,0,N-1,N-1,r1,c1,r2,c2);
		}
		printf("#%d %d\n", test+1, ret);
	}
}