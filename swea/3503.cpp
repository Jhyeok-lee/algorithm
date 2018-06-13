#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		int N;
		scanf("%d", &N);
		vector<int> jump(N,0);
		for(int i=0; i<N; i++)
			scanf("%d", &jump[i]);
		sort(jump.begin(), jump.end());

		vector<int> re(N,0);
		for(int i=0; i<N; i+=2)
			re[i/2] = jump[i];
		int idx = (N%2==1)?N-2:N-1;
		for(int i=1; i<N; i+=2)
			re[N-1-i/2] = jump[i];

		int ret = abs(re[0]-re[N-1]);
		for(int i=0; i<N-1; i++)
			ret = max(ret, abs(re[i]-re[i+1]));
		printf("#%d %d\n", test+1, ret);
	}
	return 0;
}