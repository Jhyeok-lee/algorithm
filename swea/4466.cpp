#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		int N, K;
		scanf("%d %d", &N, &K);
		vector<int> a;
		for(int i=0; i<N; i++) {
			int d;
			scanf("%d", &d);
			a.push_back(d);
		}
		sort(a.begin(), a.end());
		int ret = 0;
		for(int i=0; i<K; i++)
			ret += a[N-1-i];
		printf("#%d %d\n", test+1, ret);
	}
}