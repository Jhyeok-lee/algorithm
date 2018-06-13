#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Build {
public:
	int x,y,d;
};

int N, W, K;
bool cmp(const Build& a, const Build& b)
{
	return a.d < b.d;
}

bool cmp2(const Build& a, const Build& b)
{
	return a.x*W+a.y < b.x*W+b.y;
}
inline int ABS(int a)
{
	return a<0?-a:a;
}

vector<Build> B;
vector<bool> D;

int main(void)
{
	setbuf(stdout, NULL);
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		scanf("%d %d %d", &N, &W, &K);
		B = vector<Build>(N);
		D = vector<bool>(N, false);
		queue<int> C;
		for(int i=0; i<N; i++) {
			int x, y, d;
			scanf("%d %d %d", &x, &y, &d);
			B[i].x = x;
			B[i].y = y;
			B[i].d = d-K;
		}
		sort(B.begin(), B.end(), cmp2);

		int ret = B.size();
		for(int i=0; i<N; i++) {
			if( B[i].d <= 0 ) {
				C.push(i);
				D[i] = true;
				ret--;
			}
		}
		while( C.size() ) {
			int b = C.front();
			C.pop();
			for(int i=b-1; i>=0; i--) {
				if( D[i] )
					continue;
				int dd = 10/(ABS(B[i].x - B[b].x) + ABS(B[i].y - B[b].y));
				if( dd > 0 )
					B[i].d -= dd;
				else
					continue;
				if( B[i].d <= 0 && !D[i] ) {
					C.push(i);
					D[i] = true;
					ret--;
				}
				if( B[i].x < B[b].x - 10 )
					break;
			}
			for(int i=b+1; i<N; i++) {
				if( D[i] )
					continue;
				int dd = 10/(ABS(B[i].x - B[b].x) + ABS(B[i].y - B[b].y));
				if( dd > 0 )
					B[i].d -= dd;
				else
					continue;
				if( B[i].d <= 0 && !D[i] ) {
					C.push(i);
					D[i] = true;
					ret--;
				}
				if( B[i].x > B[b].x + 10 )
					break;
			}
		}
		printf("#%d %d\n", test+1, ret);
	}
	return 0;
}