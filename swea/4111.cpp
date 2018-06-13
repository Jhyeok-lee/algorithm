#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, K;
int camera[10000];
int cameraDist[10000];

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(camera, 0, sizeof(camera));
		memset(cameraDist, 0, sizeof(cameraDist));
		scanf("%d %d", &N, &K);
		for(int i=0; i<N; i++)
			scanf("%d", &camera[i]);
		sort(camera, camera+N);

		int ret = 0;
		for(int i=1; i<N; i++) {
			cameraDist[i-1] = camera[i] - camera[i-1];
			ret += cameraDist[i-1];
		}
		sort(cameraDist, cameraDist+N-1);

		for(int i=0; i<K-1; i++)
			ret -= cameraDist[N-2-i];
		printf("#%d %d\n", test+1, ret);
	}
}