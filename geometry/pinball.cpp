#include <iostream>
#include <vector>
#include <cstdio>
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

	V operator + (const V& r) const
	{
		return V(x+r.x, y+r.y);
	}
	V operator - (const V& r) const
	{
		return V(x-r.x, y-r.y);
	}
	V operator * (const double r) const
	{
		return V(x*r, y*r);
	}

	double size()
	{
		return hypot(x,y);
	}

	V unit()
	{
		return V(x/size(), y/size());
	}

	double dot(const V& r)
	{
		return (x*r.x) + (y*r.y);
	}

	V project(V& rhs)
	{
		V r = rhs.unit();
		return r * r.dot(*this);
	}
};

const double ZERO = 1e-9;
const double INF = 1e200;
vector<V> circle;
vector<double> rad;

vector<double> equation(double a, double b, double c)
{
	double d = b*b - 4*a*c;
	if( d < -ZERO )
		return vector<double>();
	if( d < ZERO )
		return vector<double>(1, -b/(2*a));
	vector<double> ret;
	ret.push_back( (-b-sqrt(d)) / (2*a) );
	ret.push_back( (-b+sqrt(d)) / (2*a) );
	return ret;
}

double hitCircle(V pos, V dir, V cen, double radius)
{
	double a = dir.dot(dir);
	double b = 2 * dir.dot(pos-cen);
	double c = (cen.dot(cen) + pos.dot(pos)
		-2*(pos.dot(cen)) -radius*radius);
	vector<double> ret = equation(a,b,c);
	if( ret.empty() || ret[0] < ZERO )
		return INF;
	return ret[0];
}

V reflect(V dir, V c, V contact)
{
	V a = contact-c;
	return (dir - dir.project(a)*2).unit();
}

void solve(V pos, V dir)
{
	int hitCount = 0;
	while( hitCount < 100 ) {
		int c = -1;
		double time = INF*0.5;
		for(int i=0; i<circle.size(); i++) {
			double cand = hitCircle(pos, dir, circle[i],
				rad[i]+1);
			if( cand < time ) {
				time = cand;
				c = i;
			}
		}

		if( c == -1 )
			break;
		if( hitCount++ )
			printf(" ");
		printf("%d", c);

		pos = pos + dir*time;
		dir = reflect(dir, circle[c], pos);
	}
	printf("\n");
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		circle.clear();
		rad.clear();
		double x,y,dx,dy;
		int N;
		scanf("%lf %lf %lf %lf %d", &x, &y, &dx, &dy, &N);
		V pos(x,y);
		V dir(dx,dy);
		dir = dir.unit();
		for(int i=0; i<N; i++) {
			double x,y,r;
			scanf("%lf %lf %lf", &x, &y, &r);
			V v(x,y);
			circle.push_back(v);
			rad.push_back(r);
		}
		solve(pos, dir);
	}
	return 0;
}