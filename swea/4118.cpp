#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

#define MOD 1000000007

using namespace std;

int N,M;
int parent[100000];

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		scanf("%d %d", &N, &M);
		for(int i=0; i<M; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			parent[a] = b;
		}
		printf("#%d %lld\n", test+1, (long long)pow(2, N-M)%MOD);
	}
	return 0;
}