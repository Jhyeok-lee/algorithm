#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
int score[100];
int memo[100][10001];
int count[10001];

int solve(int idx, int sum)
{
	if( idx == N )
		return 1;

	int& ret = memo[idx][sum];
	if( ret != -1 )
		return ret;

	ret = 0;
	count[sum] = 1;
	count[sum+score[idx]] = 1;
	ret += solve(idx+1, sum+score[idx]);
	ret += solve(idx+1, sum);

	return ret;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(memo, -1, sizeof(memo));
		memset(count, 0, sizeof(count));
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d", &score[i]);
		int ret = solve(0, 0);
		ret = 0;
		for(int i=0; i<=10000; i++) {
			if( count[i] )
				ret++;
		}
		printf("#%d %d\n", test+1, ret);
	}
	return 0;
}