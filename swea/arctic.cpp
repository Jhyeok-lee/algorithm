#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

class Base {
public:
	double x,y;
	Base(double _x, double _y)
	{
		x = _x;
		y = _y;
	}
};

int N;
vector<Base> b;
double dist[100][100];

bool find(double d)
{
	vector<int> visited(N,0);
	queue<int> q;
	int visit = 0;
	q.push(0);
	visited[0] = 1;
	while( !q.empty() ) {
		int here = q.front();
		q.pop();
		visit++;
		for(int there=0; there<N; there++) {
			if( !visited[there] && dist[here][there] < d ) {
				q.push(there);
				visited[there] = 1;
			}
		}
	}
	return visit == N;
}

double solve()
{
	double ret = 0;
	double lo = 0;
	double hi = 1000;
	for(int i=0; i<100; i++) {
		double mid = (lo + hi)/2;
		if( find(mid) )
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

inline double d(Base& a, Base& b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(dist, 0, sizeof(dist));
		b.clear();
		scanf("%d", &N);
		for(int i=0; i<N; i++) {
			double x,y;
			scanf("%lf %lf", &x, &y);
			Base t(x,y);
			b.push_back(t);
		}

		for(int i=0; i<N; i++) {
			for(int j=i+1; j<N; j++) {
				dist[i][j] = d(b[i],b[j]);
				dist[j][i] = dist[i][j];
			}
		}

		double ret = solve();
		printf("%.2f\n", ret);
	}
	return 0;
}