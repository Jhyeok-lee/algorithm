#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N,M,m;
int num[12];
int k[4];

void solve(int idx, int res)
{
	if( idx == N ) {
		M = max(M, res);
		m = min(m, res);
		return;
	}
	for(int i=0; i<4; i++) {
		if( k[i] > 0 ) {
			k[i]--;
			if( i == 0 )
				solve(idx+1, res+num[idx]);
			else if( i == 1 )
				solve(idx+1, res-num[idx]);
			else if( i == 2 )
				solve(idx+1, res*num[idx]);
			else if( i == 3 )
				solve(idx+1, res/num[idx]);
			k[i]++;
		}
	}
	return;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(k, 0, sizeof(k));
		scanf("%d", &N);
		for(int i=0; i<4; i++)
			scanf("%d", &k[i]);
		for(int i=0; i<N; i++)
			scanf("%d", &num[i]);
		M = -1234567890;
		m = 1234567890;
		solve(1,num[0]);
		int ret = M-m;
		printf("#%d %d\n", test+1, ret);
	}
}