#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, S;
int arr[100];
int memo[100];

int error(int a, int b)
{
	
}

int quantize(int idx)
{
	int& ret = memo[idx];
	if( ret != -1 )
		return ret;

	ret = 1234567890;
	for(int l=1; l<N && idx+l<N; l++)
		ret = min(ret, quantize(idx+l) + error(idx, idx+l-1));
	return ret;
}

int main(void)
{
	int Case;
	for(int test=0; test<Case; test++) {
		memset(memo, -1, sizeof(memo));
		scanf("%d %d", &N, &S);
		for(int i=0; i<N; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr+N);
		int ret = quantize(0);
		printf("%d\n", ret);
	}
	return 0;
}