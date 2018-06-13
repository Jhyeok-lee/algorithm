#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

class V {
public:
	double x,y;
	V(double _x, double _y)
	{
		x = _x;
		y = _y;
	}
};

int N, M;
vector<V> A;
vector<V> B;

int minPoint(const vector<V>& p, const V& q)
{
	int ret = 0;
	double dist = 1e200;
	for(int i=0; i<p.size(); i++) {
		if( dist > hypot(q.x - p[i].x, q.y - p[i].y) ) {
			ret = i;
			dist = hypot(q.x - p[i].x, q.y - p[i].y);
		}
	}
	return ret;
}

double plDist(const V& n, const V& p, const V& q)
{
	V pn(n.x-p.x, n.y-p.y);
	V pq(q.x-p.x, q.y-p.y);
	double pqsize = hypot(pq.x, pq.y);
	pq.x = pq.x/pqsize;
	pq.y = pq.y/pqsize;
	double dot = pn.x*pq.x + pn.y*pq.y;
	V project(dot*pq.x + p.x, dot*pq.y + p.y);
	V h(project.x-n.x, project.y-n.y);
	double ret = hypot(h.x, h.y);
	return ret;
}

bool isIncreasing(const V& a, const V& b1, const V& b2)
{
	double dist = hypot(a.x - b1.x, a.y - b1.y);
	double size = hypot(b2.x - b1.x, b2.y - b1.y);
	V b3((b2.x - b1.x)/size/10, (b2.y - b1.y)/size/10);
	double dist2 = hypot(b1.x - a.x + b3.x,
						b1.y - a.y + b3.y);
	if( dist < dist2 )
		return true;
	return false;
}

double minDist(const vector<V>& P, int p,
				const vector<V>& Q, int q)
{
	bool c = isIncreasing(P[p], Q[q],
						Q[(q-1+Q.size())%Q.size()]);
	bool cc = isIncreasing(P[p], Q[q],
					Q[(q+1)%Q.size()]);
	double ret = hypot(P[p].x - Q[q].x, P[p].y - Q[q].y);
	if( !c )
		ret = min(ret, plDist(P[p], Q[q], Q[(q-1+Q.size())%Q.size()]));
	else if( !cc )
		ret = min(ret, plDist(P[p], Q[q], Q[(q+1)%Q.size()]));
	return ret;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		A.clear();
		B.clear();
		scanf("%d %d", &N, &M);
		for(int i=0; i<N; i++) {
			int x,y;
			scanf("%d %d", &x, &y);
			A.push_back(V(x,y));
		}
		for(int i=0; i<M; i++) {
			int x,y;
			scanf("%d %d", &x, &y);
			B.push_back(V(x,y));
		}
		double gx = 0;
		double gy = 0;
		for(int i=0; i<N; i++) {
			gx += A[i].x;
			gy += A[i].y;
		}
		gx /= A.size();
		gy /= A.size();
		int bMin = minPoint(B, V(gx,gy));
		gx = 0;
		gy = 0;
		for(int i=0; i<M; i++) {
			gx += B[i].x;
			gy += B[i].y;
		}
		gx /= B.size();
		gy /= B.size();
		int aMin = minPoint(A, V(gx,gy));

		double ret = minDist(A, aMin, B, bMin);
		ret = min(ret, minDist(B, bMin, A, aMin));
		printf("Case #%d\n%lf\n", test+1, ret);
	}
	return 0;
}