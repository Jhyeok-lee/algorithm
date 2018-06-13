#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 1000000007

int N, M;
long long num[100001];
long long tree[300001];
long long tree2[300001];
long long lazy[300001];

long long gcd(long long a, long long b)
{
	a = abs(a);
	b = abs(b);
	if( a < b )
		swap(a,b);
	if( b == 0 )
		return a;
	return gcd(b, a%b);
}

long long init(int node, int lo, int hi)
{
	if( lo == hi )
		return tree[node] = num[lo] - num[lo-1];
	int mid = (lo+hi)/2;
	long long a = init(node*2, lo, mid);
	long long b = init(node*2+1, mid+1, hi);
	return tree[node] = gcd(a,b);
}

long long init2(int node, int lo, int hi)
{
	if( lo == hi )
		return tree2[node] = num[lo];
	int mid = (lo+hi)/2;
	long long a = init2(node*2, lo, mid);
	long long b = init2(node*2+1, mid+1, hi);
	return tree2[node] = a+b;
}

void update(int node, int lo, int hi, int idx, long long c)
{
	if( idx < lo || hi < idx )
		return;
	if( lo == hi ) {
		tree[node] += c;
		return;
	}
	int mid = (lo+hi)/2;
	update(node*2, lo, mid, idx, c);
	update(node*2+1, mid+1, hi, idx, c);
	tree[node] = gcd(tree[node*2],tree[node*2+1]);
	return;
}

void update_lazy(int node, int lo, int hi)
{
	if( lazy[node] != 0 ) {
		tree2[node] += (hi-lo+1)*lazy[node];
		if( lo != hi ) {
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update2(int node, int lo, int hi, int l, int r, long long c)
{
	update_lazy(node, lo, hi);
	if( r < lo || hi < l )
		return;
	if( l <= lo && hi <= r ) {
		tree2[node] += (hi-lo+1)*c;
		if( lo != hi ) {
			lazy[node*2] += c;
			lazy[node*2+1] += c;
		}
		return;
	}
	int mid = (lo+hi)/2;
	update2(node*2, lo, mid, l, r, c);
	update2(node*2+1, mid+1, hi, l, r, c);
	tree2[node] = tree2[node*2] + tree2[node*2+1];
}

long long query(int node, int lo, int hi, int l, int r)
{
	if( r < lo || hi < l )
		return 0;
	if( l <= lo && hi <= r )
		return tree[node];
	int mid = (lo+hi)/2;
	long long a = query(node*2, lo, mid, l, r);
	long long b = query(node*2+1, mid+1, hi, l, r);
	return gcd(a,b);
}

long long query2(int node, int lo, int hi, int l, int r)
{
	update_lazy(node, lo, hi);
	if( r < lo || hi < l )
		return 0;
	if( l <= lo && hi <= r )
		return tree2[node];
	int mid = (lo+hi)/2;
	long long a = query2(node*2, lo, mid, l, r);
	long long b = query2(node*2+1, mid+1, hi, l, r);
	return a+b;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(num, 0, sizeof(num));
		memset(tree, 0, sizeof(tree));
		memset(tree2, 0, sizeof(tree2));
		memset(lazy, 0, sizeof(lazy));
		scanf("%d %d", &N, &M);
		for(int i=1; i<=N; i++)
			scanf("%lld", &num[i]);
		init(1,1,N);
		init2(1,1,N);
		long long ret = 0;
		long long k = 0;
		for(int i=0; i<M; i++) {
			int p,l,r;
			long long c;
			scanf("%d %d %d", &p, &l, &r);
			if( p == 1 ) {
				k++;
				long long g = query(1,1,N,l+1,r);
				g = gcd(g, query2(1,1,N,l,l));
				ret = (ret + (k*g)%MOD) % MOD;
			}
			else {
				scanf("%lld", &c);
				update(1,1,N,l,c);
				update(1,1,N,r+1,-c);
				update2(1,1,N,l,r,c);
			}
		}
		printf("#%d %lld\n", test+1, ret);
	}
	return 0;
}