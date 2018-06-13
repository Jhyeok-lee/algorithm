#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

class Point {
public:
	int x,y;
};
int N;
vector<Point> a;
vector<Point> b;

int cal(int p, int q)
{
	return 1 + p + abs(a[p].x-b[q].x) + abs(a[p].y-b[q].y);
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		scanf("%d", &N);
		a = vector<Point>(N);
		b = vector<Point>(N);
		for(int i=0; i<N; i++)
			scanf("%d %d %d %d", &a[i].x, &a[i].y, &b[i].x, &b[i].y);

		int ret = 0;
		printf("Case #%d\n%d\n", test+1, ret);
	}
	return 0;
}