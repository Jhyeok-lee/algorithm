#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		int N;
		scanf("%d", &N);
		vector<int> arr(N,0);
		for(int i=0; i<N; i++)
			scanf("%d", &arr[i]);
		sort(arr.begin(), arr.end());
		int ret = 0;
		for(int i=0; i<N; i+=2)
			ret += arr[i];
		for(int i=1; i<N; i+=2)
			ret -= arr[i];
		printf("Case #%d\n%d\n", test+1, ret);
	}
	return 0;
}